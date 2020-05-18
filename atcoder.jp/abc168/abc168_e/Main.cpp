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

ll sign(ll A){
    return (A>0)-(A<0);
}

mint pow(ll x, ll y){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    mint a = pow(x, y/2);
    return a * a;
  }
  mint b = pow(x, y/2);
  return b * b * x;
}

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N), B(N);
  ll zero = 0;
  map<pair<ll, ll>, pair<ll, ll>> s;
  rep(i, N){
    cin >> A.at(i) >> B.at(i);
    if(A.at(i) == 0 && B.at(i) == 0){
      zero++;
    }
    else if(B.at(i) > 0){
      ll g = gcd(A.at(i), B.at(i));
      if(A.at(i) <= 0){
        ll tmp = A.at(i);
        A.at(i) = B.at(i);
        B.at(i) = -1 * tmp;
        s[make_pair(A.at(i)/g, B.at(i)/g)].second++;
      }
      else{
        s[make_pair(A.at(i)/g, B.at(i)/g)].first++;
      }
    }
    else if(B.at(i) < 0){
      A.at(i) *= -1;
      B.at(i) *= -1;
      ll g = gcd(A.at(i), B.at(i));
      if(A.at(i) <= 0){
        ll tmp = A.at(i);
        A.at(i) = B.at(i);
        B.at(i) = -1 * tmp;
        s[make_pair(A.at(i)/g, B.at(i)/g)].second++;
      }
      else{
        s[make_pair(A.at(i)/g, B.at(i)/g)].first++;
      }
    }
    else{
      s[make_pair(1, 0)].first++;
    }
  }
  vector<mint> R(0);
  set<pair<ll, ll>> T;
  mint ans = 1;
  for(auto p : s){
    //cout << p.first.first << " " << p.first.second << endl;
    //cout << p.second.first << endl;
    //cout << p.second.second << endl;
    mint now = 0;
    now += mint(2).pow(p.second.first);
    now += mint(2).pow(p.second.second);
    now -= 1;
    //cout << "now: " << now << endl;
    ans *= now;
  }
  ans -= 1;
  ans += zero;
  cout << ans << endl;
}
