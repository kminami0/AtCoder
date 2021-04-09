#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
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
    string S;
    cin >> S;
    vector<mint> dp0(sz(S)+1, 0);
    vector<mint> dp1(sz(S)+1, 0);
    vector<mint> dp2(sz(S)+1, 0);
    vector<mint> dp3(sz(S)+1, 0);
    dp0.at(0) = 1;
    rep(i, sz(S)){
        if(S.at(i) == 'A'){
            dp0.at(i+1) = dp0.at(i);
            dp1.at(i+1) = dp1.at(i) + dp0.at(i);
            dp2.at(i+1) = dp2.at(i);
            dp3.at(i+1) = dp3.at(i);
        }
        else if(S.at(i) == 'B'){
            dp0.at(i+1) = dp0.at(i);
            dp1.at(i+1) = dp1.at(i);
            dp2.at(i+1) = dp2.at(i) + dp1.at(i);
            dp3.at(i+1) = dp3.at(i);
        }
        else if(S.at(i) == 'C'){
            dp0.at(i+1) = dp0.at(i);
            dp1.at(i+1) = dp1.at(i);
            dp2.at(i+1) = dp2.at(i);
            dp3.at(i+1) = dp3.at(i) + dp2.at(i);
        }
        else{
            dp0.at(i+1) += dp0.at(i);
            dp1.at(i+1) += dp1.at(i) + dp0.at(i);
            dp2.at(i+1) += dp2.at(i);
            dp3.at(i+1) += dp3.at(i);
            dp0.at(i+1) += dp0.at(i);
            dp1.at(i+1) += dp1.at(i);
            dp2.at(i+1) += dp2.at(i) + dp1.at(i);
            dp3.at(i+1) += dp3.at(i);
            dp0.at(i+1) += dp0.at(i);
            dp1.at(i+1) += dp1.at(i);
            dp2.at(i+1) += dp2.at(i);
            dp3.at(i+1) += dp3.at(i) + dp2.at(i);
        }
    }
    cout << dp3.at(sz(S)) << '\n';
}