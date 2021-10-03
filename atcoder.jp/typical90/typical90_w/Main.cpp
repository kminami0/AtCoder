#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
#define EPSILON 1e-14
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
  if ((x += a.x) >= mod) x -= mod;
  return *this;
  }
  mint& operator-=(const mint a) {
  if ((x += mod-a.x) >= mod) x -= mod;
  return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
  if (!t) return 1;
  mint a = pow(t>>1);
  a *= a;
  if (t&1) a *= *this;
  return a;
  }
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

ll H, W;
vector<int> cnt(25);
//cnt.at(i)は第i列目のマスの直前W+1マスの状態数
vector<vector<bool>> used(25, vector<bool>(25));
vector<vector<ll>> state(25, vector<ll>(1<<18));
//state.at(i).at(j)は第i列目のマスの直前W+1マスの状態番号がjであるときの、直前W+1マスの状態
vector<map<ll, pair<ll, bool>>> Map(25);
//Map.at(i).at(j)は第i列目のマスの直前W+1マスの状態がjであるとき、その状態番号と置くことが可能かを返す

bool judge(ll sx, ll sy){
    vector<ll> dx = { 1, 1, 1, 0, -1, -1, -1, 0 };
    vector<ll> dy = { -1, 0, 1, 1, 1, 0, -1, -1 };
    rep(i, 8){
        ll tx = sx + dx.at(i);
        ll ty = sy + dy.at(i);
        if(tx < 0 || ty < 0 || ty >= W){
            continue;
        }
        if(used.at(tx).at(ty)){
            return false;
        }
    }
    return true;
}

void dfs(ll pos, ll dep, ll str){
    ll sx = pos / W;
    ll sy = pos % W;
    if(dep == W+1){
        ll idx = cnt.at(sy);
        bool flag = judge(sx, sy);
        state.at(sy).at(idx) = str;
        Map.at(sy)[str] = {idx, flag};
        cnt.at(sy)++;
        return;
    }
    dfs(pos+1, dep+1, str);
    if(judge(sx, sy)){
        used.at(sx).at(sy) = true;
        dfs(pos+1, dep+1, str+(1<<dep));
        used.at(sx).at(sy) = false;
    }
}

int main()
{
    cin >> H >> W;
    vector<string> C(H);
    rep(i, H){
        cin >> C.at(i);
    }
    rep(i, W){
        dfs(i, 0, 0);
    }
    vector<vector<ll>> nex0(25, vector<ll>(1<<18));
    //nex0.at(i).at(j)は第i列のマスを見ていて直前W+1マスの状態番号がjであるとき、そのマスに駒を置かなかったときの、次のマスからの直前W+1マスの状態番号
    vector<vector<ll>> nex1(25, vector<ll>(1<<18));
    //nex0.at(i).at(j)は第i列のマスを見ていて直前W+1マスの状態番号がjであるとき、そのマスに駒を置いたときの、次のマスからの直前W+1マスの状態番号
    rep(i, W){
        rep(j, cnt.at(i)){
            ll t = state.at(i).at(j);
            ll t0 = (t >> 1);
            ll t1 = (t >> 1) + (1 << W);
            nex0.at(i).at(j) = Map.at((i+1)%W)[t0].first;
            if(Map.at(i)[t].second){
                nex1.at(i).at(j) = Map.at((i+1)%W)[t1].first;
            }
            else{
                nex1.at(i).at(j) = -1;
            }
        }
    }
    vector<vector<vector<mint>>> dp(25, vector<vector<mint>>(25, vector<mint>(1<<18)));
    //dp.at(i).at(j).at(k)はi行j列目の直前W+1マスが番号kの状態であるような状態数
    dp.at(0).at(0).at(0) = 1;
    rep(i, H){
        rep(j, W){
            ll n1 = i;
            ll n2 = j+1;
            if(n2 == W){
                n1++;
                n2 = 0;
            }
            rep(k, cnt.at(j)){
                if(dp.at(i).at(j).at(k).x == 0){
                    continue;
                }
                dp.at(n1).at(n2).at(nex0.at(j).at(k)) += dp.at(i).at(j).at(k);
                if(nex1.at(j).at(k) != -1 && C.at(i).at(j) == '.'){
                    dp.at(n1).at(n2).at(nex1.at(j).at(k)) += dp.at(i).at(j).at(k);
                }
            }
        }
    }
    mint ans = 0;
    rep(i, cnt.at(0)){
        ans += dp.at(H).at(0).at(i);
    }
    cout << ans << '\n';
}