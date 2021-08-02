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
};
vector<vector<edge>> graph;

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;
    graph.resize(N);
    rep(i, M){
        ll U, V;
        cin >> U >> V;
        U--;
        V--;
        graph.at(U).push_back({V});
        graph.at(V).push_back({U});
    }
    rep(i, N){
        graph.at(i).push_back({i});
    }
    vector<vector<mint>> dp(K+1, vector<mint>(N, 0));
    dp.at(0).at(0) = 1;
    vector<mint> sum(K+1, 0);
    sum.at(0) = 1;
    rep(i, K){
        rep(j, N){
            mint com = 0;
            for(edge e : graph.at(j)){
                com += dp.at(i).at(e.to);
            }
            dp.at(i+1).at(j) = sum.at(i) - com;
            sum.at(i+1) += dp.at(i+1).at(j);
        }
    }
    cout << dp.at(K).at(0) << '\n';
}