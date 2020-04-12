#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
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
const int mod = 10000;
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

vector<vector<mint>> dp(101, vector<mint>(12, 0));
// dp.at(i).at(j)はi日目までの予定で、パターンがjのものの個数

int main(){
  ll N, K;
  cin >> N >> K;
  vector<ll> A(K), B(K);
  bool p = true;
  rep(i, K){
    cin >> A.at(i) >> B.at(i);
    if(A.at(i) == 1){
      dp.at(1).at(B.at(i)+8) = 1;
      p = false;
    }
  }
  if(p){
    dp.at(1).at(9) = 1;
    dp.at(1).at(10) = 1;
    dp.at(1).at(11) = 1;
  }
  bool q = true;
  rep(j, 9){
    rep(k, K){
      if(A.at(k) == 2){
        if(B.at(k) == 1){
          dp.at(2).at(0) = dp.at(1).at(9);
          dp.at(2).at(3) = dp.at(1).at(10);
          dp.at(2).at(6) = dp.at(1).at(11);
        }
        if(B.at(k) == 2){
          dp.at(2).at(1) = dp.at(1).at(9);
          dp.at(2).at(4) = dp.at(1).at(10);
          dp.at(2).at(7) = dp.at(1).at(11);
        }
        if(B.at(k) == 3){
          dp.at(2).at(2) = dp.at(1).at(9);
          dp.at(2).at(5) = dp.at(1).at(10);
          dp.at(2).at(8) = dp.at(1).at(11);
        }
        q = false;
      }
    }
  }
  if(q){
    dp.at(2).at(0) = dp.at(1).at(9);
    dp.at(2).at(3) = dp.at(1).at(10);
    dp.at(2).at(6) = dp.at(1).at(11);
    dp.at(2).at(1) = dp.at(1).at(9);
    dp.at(2).at(4) = dp.at(1).at(10);
    dp.at(2).at(7) = dp.at(1).at(11);
    dp.at(2).at(2) = dp.at(1).at(9);
    dp.at(2).at(5) = dp.at(1).at(10);
    dp.at(2).at(8) = dp.at(1).at(11);
  }
  vector<bool> r(N, true);
  rep2(i, 2, N){
    rep(k, K){
      if(A.at(k) == i+1){
        if(B.at(k) == 1){
          dp.at(i+1).at(0) = dp.at(i).at(3) + dp.at(i).at(6);
          dp.at(i+1).at(3) = dp.at(i).at(1) + dp.at(i).at(4) + dp.at(i).at(7);
          dp.at(i+1).at(6) = dp.at(i).at(2) + dp.at(i).at(5) + dp.at(i).at(8);
        }
        if(B.at(k) == 2){
          dp.at(i+1).at(1) = dp.at(i).at(0) + dp.at(i).at(3) + dp.at(i).at(6);
          dp.at(i+1).at(4) = dp.at(i).at(1) + dp.at(i).at(7);
          dp.at(i+1).at(7) = dp.at(i).at(2) + dp.at(i).at(5) + dp.at(i).at(8);
        }
        if(B.at(k) == 3){
          dp.at(i+1).at(2) = dp.at(i).at(0) + dp.at(i).at(3) + dp.at(i).at(6);
          dp.at(i+1).at(5) = dp.at(i).at(1) + dp.at(i).at(4) + dp.at(i).at(7);
          dp.at(i+1).at(8) = dp.at(i).at(2) + dp.at(i).at(5);
        }
        r.at(i) = false;
      }
    }
    if(r.at(i)){
      dp.at(i+1).at(0) = dp.at(i).at(3) + dp.at(i).at(6);
      dp.at(i+1).at(3) = dp.at(i).at(1) + dp.at(i).at(4) + dp.at(i).at(7);
      dp.at(i+1).at(6) = dp.at(i).at(2) + dp.at(i).at(5) + dp.at(i).at(8);
      dp.at(i+1).at(1) = dp.at(i).at(0) + dp.at(i).at(3) + dp.at(i).at(6);
      dp.at(i+1).at(4) = dp.at(i).at(1) + dp.at(i).at(7);
      dp.at(i+1).at(7) = dp.at(i).at(2) + dp.at(i).at(5) + dp.at(i).at(8);
      dp.at(i+1).at(2) = dp.at(i).at(0) + dp.at(i).at(3) + dp.at(i).at(6);
      dp.at(i+1).at(5) = dp.at(i).at(1) + dp.at(i).at(4) + dp.at(i).at(7);
      dp.at(i+1).at(8) = dp.at(i).at(2) + dp.at(i).at(5);
    }
  }
  mint ans = 0;
  rep(i, 9){
    ans += dp.at(N).at(i);
  }
  cout << ans << endl;
}