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

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> B(N);
    rep(i, N) cin >> B.at(i);
    vector<pair<ll, ll>> P(N);
    rep(i, N){
        P.at(i) = {A.at(i), B.at(i)};
    }
    sort(all(P));
    vector<vector<vector<mint>>> dp(2, vector<vector<mint>>(5001, vector<mint>(2, 0)));
    dp.at(0).at(0).at(0) = 1;
    mint ans = 0;
    rep(i, N){
        rep(j, 5001){
            dp.at(1).at(j).at(0) = dp.at(0).at(j).at(0) + dp.at(0).at(j).at(1);
        }
        rep(j, P.at(i).second){
            dp.at(1).at(j).at(1) = 0;
        }
        rep(j, 5001 - P.at(i).second){
            dp.at(1).at(j+P.at(i).second).at(1) = dp.at(0).at(j).at(0) + dp.at(0).at(j).at(1);
        }
        rep(j, P.at(i).first){
            ans += dp.at(1).at(j+1).at(1);
        }
        rep(j, 5001){
            rep(k, 2){
                dp.at(0).at(j).at(k) = dp.at(1).at(j).at(k);
            }
        }
    }
    cout << ans << '\n';
}