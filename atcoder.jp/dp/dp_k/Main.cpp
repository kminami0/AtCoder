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

vector<vector<bool>> dp(100001, vector<bool>(2, false));
//dp.at(i).at(j)はj=0なら太郎君の手番で山が残りi個のときに太郎君が勝つかどうか
//j=1なら次郎君の手番で山が残りi個のときに太郎君が勝つかどうか

int main(){
  ll N, K;
  cin >> N >> K;
  vector<ll> a(N);
  rep(i, N){
    cin >> a.at(i);
  }
  dp.at(0).at(1) = true;
  rep(i, K){
    dp.at(i+1).at(0) = false;
    dp.at(i+1).at(1) = true;
    rep(j, N){
      if(i+1 >= a.at(j)){
        dp.at(i+1).at(0) = dp.at(i+1).at(0) || dp.at(i+1-a.at(j)).at(1);
        dp.at(i+1).at(1) = dp.at(i+1).at(1) && dp.at(i+1-a.at(j)).at(0);
      }
    }
  }
  if(dp.at(K).at(0)){
    cout << "First" << endl;
  }
  else{
    cout << "Second" << endl;
  }
}