#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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

//浮動小数点はなるべく使うな、powも気をつけろ

mint mpow(mint x, ll y){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    mint a = mpow(x, y / 2);
    return a * a;
  }
  else{
    mint a = mpow(x, y / 2);
    return a * a * x;
  }
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<vector<ll>> acc(60, vector<ll>(N+1, 0));
    rep(i, 60){
        rep(j, N){
            bitset<60> s(A.at(j));
            if(s.test(i)){
                acc.at(i).at(j+1) = acc.at(i).at(j) + 1;
            }
            else{
                acc.at(i).at(j+1) = acc.at(i).at(j);
            }
        }
    }
    mint ans = 0;
    rep(i, 60){
        rep(j, N-1){
            bitset<60> s(A.at(j));
            if(s.test(i)){
                ans += mpow(2, i) * ((N-1-j) - (acc.at(i).at(N) - acc.at(i).at(j+1)));
            }
            else{
                ans += mpow(2, i) * (acc.at(i).at(N) - acc.at(i).at(j+1));
            }
        }
    }
    cout << ans << '\n';
}