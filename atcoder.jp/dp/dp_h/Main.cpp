#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000009
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

vector<vector<mint>> dp(1000, vector<mint>(1000, 0));

int main(){
  ll H, W;
  cin >> H >> W;
  vector<string> a(H);
  rep(i, H){
    cin >> a.at(i);
  }
  dp.at(0).at(0) = 1;
  rep(i, H){
    rep(j, W){
      if(i == 0 && j == 0){
        continue;
      }
      if(a.at(i).at(j) == '#'){
        continue;
      }
      if(i == 0){
        if(a.at(0).at(j-1) == '.'){
          dp.at(0).at(j) = dp.at(0).at(j-1);
        }
      }
      else if(j == 0){
        if(a.at(i-1).at(0) == '.'){
          dp.at(i).at(0) = dp.at(i-1).at(0);
        }
      }
      else{
        if(a.at(i-1).at(j) == '.'){
          dp.at(i).at(j) += dp.at(i-1).at(j);
        }
        if(a.at(i).at(j-1) == '.'){
          dp.at(i).at(j) += dp.at(i).at(j-1);
        }
      }
    }
  }
  cout << dp.at(H-1).at(W-1).x << endl;
}