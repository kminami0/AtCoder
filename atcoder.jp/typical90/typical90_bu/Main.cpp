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

struct edge {
  ll to;
};
vector<vector<edge>> graph;

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

vector<bool> vst(100000, false);
vector<vector<mint>> dp(100000, vector<mint>(3, 0));
string c = "";

void dfs(ll x, ll p = -1){
    if(vst.at(x)){
        return;
    }
    vst.at(x) = true;
    for(edge e : graph.at(x)){
        dfs(e.to, x);
    }
    if(sz(graph.at(x)) == 1 && p != -1){
        if(c.at(x) == 'a'){
            dp.at(x).at(0) = 1;
        }
        else{
            dp.at(x).at(1) = 1;
        }
    }
    else{
        mint temp = 1;
        if(c.at(x) == 'a'){
            for(edge e : graph.at(x)){
                if(e.to == p){
                    continue;
                }
                temp *= dp.at(e.to).at(0) + dp.at(e.to).at(2);
            }
            dp.at(x).at(0) = temp;
            temp = 1;
            for(edge e : graph.at(x)){
                if(e.to == p){
                    continue;
                }
                temp *= dp.at(e.to).at(0) + dp.at(e.to).at(1) + dp.at(e.to).at(2) * 2;
            }
            dp.at(x).at(2) = temp - dp.at(x).at(0);
        }
        else{
            for(edge e : graph.at(x)){
                if(e.to == p){
                    continue;
                }
                temp *= dp.at(e.to).at(1) + dp.at(e.to).at(2);
            }
            dp.at(x).at(1) = temp;
            temp = 1;
            for(edge e : graph.at(x)){
                if(e.to == p){
                    continue;
                }
                temp *= dp.at(e.to).at(0) + dp.at(e.to).at(1) + dp.at(e.to).at(2) * 2;
            }
            dp.at(x).at(2) = temp - dp.at(x).at(1);
        }
    }
}

int main()
{
    ll N;
    cin >> N;
    graph.resize(N);
    rep(i, N){
        char x;
        cin >> x;
        c += x;
    }
    rep(i, N-1){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).push_back({b});
        graph.at(b).push_back({a});
    }
    dfs(0);
    cout << dp.at(0).at(2) << '\n';
}