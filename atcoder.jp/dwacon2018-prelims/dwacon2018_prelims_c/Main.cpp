#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
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

vector<vector<mint>> dp(101, vector<mint>(1001));
vector<vector<mint>> dp2(101, vector<mint>(1001));
vector<vector<mint>> pt(1001, vector<mint>(101, 0));

void part(int x, int k){
  rep(i, x+1){
    pt.at(i).at(1) = 1;
  }
  rep(i, x+1){
    rep2(j, 2, k+1){
      if(i >= j){
        pt.at(i).at(j) = pt.at(i-j).at(j) + pt.at(i).at(j-1);
      }
      else{
        pt.at(i).at(j) = pt.at(i).at(j-1);
      }
    }
  }
  return;
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<ll> killA(N), killB(M);
  rep(i, N){
    cin >> killA.at(i);
  }
  rep(i, M){
    cin >> killB.at(i);
  }
  vector<int> k(0);
  k.push_back(1);
  int a = 0;
  rep(j, N-1){
    if(killA.at(j) == killA.at(j+1)){
      k.at(a)++;
    }
    else{
      k.push_back(1);
      a++;
    }
  }
  int killBsum = 0;
  rep(i, M){
    killBsum += killB.at(i);
  }
  int killAsum = 0;
  rep(i, N){
    killAsum += killA.at(i);
  }
  part(max(killAsum, killBsum), max(N, M));
  dp.at(0).at(0) = 1;
  rep(i, sz(k)){
    rep(j, killBsum+1){
      rep(x, killBsum-j+1){
        dp.at(i+1).at(j+x) += dp.at(i).at(j) * pt.at(x).at(k.at(i));
      }
    }
  }
  vector<int> k2(0);
  k2.push_back(1);
  int a2 = 0;
  rep(j, M-1){
    if(killB.at(j) == killB.at(j+1)){
      k2.at(a2)++;
    }
    else{
      k2.push_back(1);
      a2++;
    }
  }
  dp2.at(0).at(0) = 1;
  rep(i, sz(k2)){
    rep(j, killAsum+1){
      rep(x, killAsum-j+1){
        dp2.at(i+1).at(j+x) += dp2.at(i).at(j) * pt.at(x).at(k2.at(i));
      }
    }
  }
  cout << (dp.at(sz(k)).at(killBsum) * dp2.at(sz(k2)).at(killAsum)).x << endl;
}