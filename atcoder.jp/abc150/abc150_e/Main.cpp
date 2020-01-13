#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000000
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

using ll = long long;

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
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

int64_t mpow(int64_t x, int64_t y){
  if(y < 0){
    return 0;
  }
  else if(y == 0){
    return 1;
  }
  int64_t ans = x;
  int64_t z = floor(log2(y));
  rep(i, z){
    ans *= ans;
    ans %= 1000000007;
  }
  rep(i, y - pow(2, z)){
    ans *= x;
    ans %= 1000000007;
  }
  return ans;
}

int main(){
  int64_t N;
  cin >> N;
  vector<int64_t> C(N);
  rep(i, N){
    cin >> C.at(i);
  }
  sort(all(C));
  mint cost = 0;
  vector<mint> two(N+1);
  two.at(0) = 1;
  rep(i, N){
    two.at(i+1) = two.at(i) * 2;
  }
  rep(i, N){
    mint tcost = 0;
    if(i != N - 1){
      tcost += two.at(N - i - 2);
      tcost *= (N - i - 1);
    }
    tcost += two.at(N - i - 1);
    tcost *= C.at(i);
    tcost *= two.at(i);
    cost += tcost;
  }
  cost *= two.at(N);
  cout << cost.x << endl;
}