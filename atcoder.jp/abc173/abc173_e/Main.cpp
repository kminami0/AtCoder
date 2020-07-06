#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000000000000 //10^15
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
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A.at(i);
  vector<ll> pos(0);
  vector<ll> neg(0);
  sort(all(A));
  reverse(all(A));
  bool fu = false;
  rep(i, N){
    if(A.at(i) < 0){
      fu = true;
    }
    if(fu){
      neg.push_back(A.at(i));
    }
    else{
      pos.push_back(A.at(i));
    }
  }
  vector<pair<ll, ll>> z(N);
  rep(i, N){
    if(A.at(i) >= 0){
      z.at(i) = make_pair(A.at(i), 1);
    }
    else{
      z.at(i) = make_pair(-1*A.at(i), -1);
    }
  }
  sort(all(z));
  reverse(all(z));
  bool pp = false;
  ll x = sz(pos);
  ll y = sz(neg);
  ll w = K - sz(pos);
  bool s = y > w;
  bool t = sz(pos) != 0;
  if((K - sz(pos)) % 2 == 0){
    pp = true;
  }
  else if(y > w && sz(pos) != 0){
    pp = true;
  }
  mint ans = 1;
  sort(all(pos));
  sort(all(neg));
  if(pp){
    vector<ll> dn(0);
    rep(i, sz(neg)/2){
      dn.push_back(neg.at(2*i)*neg.at(2*i+1));
    }
    if(K % 2 == 1){
      ans *= pos.at(sz(pos)-1);
      pos.pop_back();
      K--;
    }
    reverse(all(pos));
    rep(i, sz(pos)/2){
      dn.push_back(pos.at(2*i)*pos.at(2*i+1));
    }
    sort(all(dn));
    reverse(all(dn));
    rep(i, K/2){
      ans *= dn.at(i);
    }
  }
  else{
    sort(all(z));
    rep(i, K){
      ans *= z.at(i).first * z.at(i).second;
    }
  }
  cout << ans << endl; 
}