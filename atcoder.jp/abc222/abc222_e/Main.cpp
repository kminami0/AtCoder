#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
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
const int mod = 998244353;
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

struct edge {
  ll to;
  ll num;
};
vector<vector<edge>> graph;

vector<vector<ll>> parent(11, vector<ll>(1000, -1)); // parent.at(k).at(u) = uの2^k個上の祖先
vector<set<ll>> path(1000); //path.at(i)は頂点0から頂点iへ移動する際に通過する辺の番号の集合

void dfs(ll x, ll p, ll n){
    parent.at(0).at(x) = p;
    if(p != -1){
        path.at(x) = path.at(p);
        path.at(x).insert(n);
    }
    for(auto e : graph.at(x)){
        if(e.to != p){
            dfs(e.to, x, e.num);
        }
    }
}

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;
    graph.resize(N);
    vector<ll> A(M);
    rep(i, M){
        cin >> A.at(i);
        A.at(i)--;
    }
    rep(i, N-1){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        graph.at(u).push_back({v, i});
        graph.at(v).push_back({u, i});
    }
    dfs(0, -1, -1);
    rep(i, 10){
        rep(j, N){
            if(parent.at(i).at(j) < 0){
                parent.at(i+1).at(j) = -1;
            }
            else{
                parent.at(i+1).at(j) = parent.at(i).at(parent.at(i).at(j));
            }
        }
    }
    vector<ll> pass(N-1, 0);
    ll sum = 0;
    rep(i, M-1){
        set<ll> L, R;
        set_difference(all(path.at(A.at(i))), all(path.at(A.at(i+1))), inserter(L, end(L)));
        set_difference(all(path.at(A.at(i+1))), all(path.at(A.at(i))), inserter(R, end(R)));
        for(ll x : L){
            pass.at(x)++;
            sum++;
        }
        for(ll x : R){
            pass.at(x)++;
            sum++;
        }
    }
    vector<mint> pre(199909, 0);
    vector<mint> now(199909, 0);
    pre.at(0) = 1;
    rep(i, N-1){
        rep(j, 199909){
            if(j < pass.at(i)){
                now.at(j) = pre.at(j);
            }
            else{
                now.at(j) = pre.at(j) + pre.at(j-pass.at(i));
            }
        }
        rep(j, 199909){
            pre.at(j) = now.at(j);
        }
    }
    if((K+sum) % 2 != 0){
        cout << 0 << '\n';
        return 0;
    }
    if(sum-K < 0 || sum+K < 0){
        cout << 0 << '\n';
        return 0;
    }
    cout << now.at((sum-K)/2) << '\n';
}