#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14 100兆
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
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

vector<mint> fac(2000003, 1);

void calc(int n){
  rep(i, n){
    fac.at(i+1) = fac.at(i) * (i+1);
  }
  return;
}

mint f(int r, int c){ // (r+c)!/(r!c!)
  mint a = fac.at(r+c);
  mint b = fac.at(r);
  mint d = fac.at(c);
  mint ans = a / (b * d);
  return ans;
}

mint mpow(ll a, ll b){ // a^b
  if(b == 0){
    return 1;
  }
  mint p = 1;
  if(b % 2 == 0){
    p = mpow(a, b/2) * mpow(a, b/2);
  }
  else{
    p = mpow(a, b/2) * mpow(a, b/2) * a;
  }
  return p;
}

vector<mint> mp(2000003, 1);

void calc2(ll x, ll y){
  rep(i, y){
    mp.at(i+1) = mp.at(i) * x;
  }
  return;
}
  
int main(){
  ll N, M, K;
  cin >> N >> M >> K;
  calc(N);
  calc2(M-1, N);
  mint ans = 0;
  rep2(i, N-1-K, N){
    ans += f(N-1-i, i) * M * mp.at(i);
  }
  cout << ans << endl;
}