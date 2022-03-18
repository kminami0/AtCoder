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

int main()
{
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    rep(i, n) cin >> a.at(i);
    vector<vector<mint>> dp(n+1, vector<mint>(1<<(2*d+1), 0));
    dp.at(0).at(0) = 1;
    rep(i, n){
        if(a.at(i) != -1){
            rep(j, (1<<(2*d+1))){
                bitset<12> s(j);
                ll dt = a.at(i) - (i + 1 - d);
                ll x = j >> 1;
                if(!s.test(dt+1)){
                    dp.at(i+1).at(x | (1 << dt)) += dp.at(i).at(j);
                }
            }
        }
        else{
            rep(j, (1<<(2*d+1))){
                bitset<12> s(j);
                rep2(k, max(0LL, d-i), min(2*d+1, d+n-i)){
                    ll x = j >> 1;
                    if(!s.test(k+1)){
                        dp.at(i+1).at(x | (1 << k)) += dp.at(i).at(j);
                    }
                }
            }
        }
        //cout << i << "-th" << endl;
        //rep(j, n+1){
        //    rep(k, 1 << (2*d+1)){
        //        cout << j << " " << k << " " << dp.at(j).at(k) << endl;
        //    }
        //}
    }
    ll y = (1 << (d+1)) - 1;
    cout << dp.at(n).at(y) << '\n';
}