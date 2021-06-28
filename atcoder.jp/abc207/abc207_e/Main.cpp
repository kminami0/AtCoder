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

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<vector<ll>> acc(N+1, vector<ll>(N+1, 0));
    rep(i, N){
        rep2(j, 1, N+1){
            acc.at(i+1).at(j) = (acc.at(i).at(j) + A.at(i)) % j;
        }
    }
    vector<vector<mint>> dp(N+1, vector<mint>(N+1, 0));
    //dp.at(i).at(j)はi番目までの部分列をj個に分割する方法の数
    dp.at(0).at(0) = 1;
    vector<vector<mint>> memo(N+1, vector<mint>(N+1, 0));
    //memo.at(i).at(j)はacc.at(k).at(i)==jとなる全てのkにおけるdp.at(k).at(i-1)の総和;
    memo.at(1).at(0) = 1;
    rep(i, N){
        rep2(j, 1, N+1){
            dp.at(i+1).at(j) = memo.at(j).at(acc.at(i+1).at(j));
            //右辺はacc.at(k).at(j)==acc.at(i+1).at(j)となる全てのkにおけるdp.at(k).at(j-1)の総和
            //cout << i+1 << " " << j << " " << dp.at(i+1).at(j) << endl;
        }
        rep2(j, 2, N+1){
            memo.at(j).at(acc.at(i+1).at(j)) += dp.at(i+1).at(j-1);
        }
    }
    mint ans = 0;
    rep(i, N){
        ans += dp.at(N).at(i+1);
    }
    cout << ans << '\n';
}