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
const int mod = 100000;
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

vector<vector<vector<mint>>> dp(101, vector<vector<mint>>(101, vector<mint>(4, 0)));
//dp.at(i).at(j).at(0)は直近がrrで、(i,j)から行く方法
//dp.at(i).at(j).at(1)は直近がruで、(i,j)から行く方法
//dp.at(i).at(j).at(2)は直近がurで、(i,j)から行く方法
//dp.at(i).at(j).at(3)は直近がuuで、(i,j)から行く方法

int main(){
  int w, h;
  cin >> w >> h;
  rep(i, 4){
    dp.at(w).at(h).at(i) = 1;
  }
  rep(i, w){
    rep(j, h){
      if(i == 0 && j == 0){
        continue;
      }
      else if(i == 0){
        dp.at(w).at(h-j).at(0) = dp.at(w).at(h-j+1).at(1);
        dp.at(w).at(h-j).at(1) = dp.at(w).at(h-j+1).at(3);
        dp.at(w).at(h-j).at(2) = 0;
        dp.at(w).at(h-j).at(3) = dp.at(w).at(h-j+1).at(3);
      }
      else if(j == 0){
        dp.at(w-i).at(h).at(0) = dp.at(w-i+1).at(h).at(0);
        dp.at(w-i).at(h).at(1) = 0;
        dp.at(w-i).at(h).at(2) = dp.at(w-i+1).at(h).at(0);
        dp.at(w-i).at(h).at(3) = dp.at(w-i+1).at(h).at(2);
      }
      else{
        dp.at(w-i).at(h-j).at(0) = dp.at(w-i+1).at(h-j).at(0) + dp.at(w-i).at(h-j+1).at(1);
        dp.at(w-i).at(h-j).at(1) = dp.at(w-i).at(h-j+1).at(3);
        dp.at(w-i).at(h-j).at(2) = dp.at(w-i+1).at(h-j).at(0);
        dp.at(w-i).at(h-j).at(3) = dp.at(w-i+1).at(h-j).at(2) + dp.at(w-i).at(h-j+1).at(3);
      }
    }
  }
  cout << (dp.at(1).at(1).at(1)+dp.at(1).at(1).at(2)).x << endl;
}