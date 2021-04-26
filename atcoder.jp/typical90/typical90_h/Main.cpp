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
    ll N;
    string S;
    cin >> N >> S;
    vector<vector<mint>> dp(N+1, vector<mint>(8, 0));
    dp.at(0).at(0) = 1;
    rep(i, N){
        if(S.at(i) == 'a'){
            dp.at(i+1).at(1) += dp.at(i).at(0);
            rep(j, 8){
                dp.at(i+1).at(j) += dp.at(i).at(j);
            }
        }
        else if(S.at(i) == 't'){
            dp.at(i+1).at(2) += dp.at(i).at(1);
            rep(j, 8){
                dp.at(i+1).at(j) += dp.at(i).at(j);
            }
        }
        else if(S.at(i) == 'c'){
            dp.at(i+1).at(3) += dp.at(i).at(2);
            rep(j, 8){
                dp.at(i+1).at(j) += dp.at(i).at(j);
            }
        }
        else if(S.at(i) == 'o'){
            dp.at(i+1).at(4) += dp.at(i).at(3);
            rep(j, 8){
                dp.at(i+1).at(j) += dp.at(i).at(j);
            }
        }
        else if(S.at(i) == 'd'){
            dp.at(i+1).at(5) += dp.at(i).at(4);
            rep(j, 8){
                dp.at(i+1).at(j) += dp.at(i).at(j);
            }
        }
        else if(S.at(i) == 'e'){
            dp.at(i+1).at(6) += dp.at(i).at(5);
            rep(j, 8){
                dp.at(i+1).at(j) += dp.at(i).at(j);
            }
        }
        else if(S.at(i) == 'r'){
            dp.at(i+1).at(7) += dp.at(i).at(6);
            rep(j, 8){
                dp.at(i+1).at(j) += dp.at(i).at(j);
            }
        }
        else{
            rep(j, 8){
                dp.at(i+1).at(j) += dp.at(i).at(j);
            }
        }
    }
    cout << dp.at(N).at(7) << '\n';
}