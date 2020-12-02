#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
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
    ll H, W, K;
    cin >> H >> W >> K;
    vector<vector<mint>> dp(H+1, vector<mint>(W, 0));
    //dp.at(i).at(j)は長さi+1の縦棒であみだくじを作ったときに1からj+1に到達する作り方の数
    dp.at(0).at(0) = 1;
    rep(i, H){
        rep(k, 1 << (W-1)){
            bitset<8> s(k);
            bool valid = true;
            rep(l, W-2){
                if(s.test(l) && s.test(l+1)){
                    valid = false;
                    break;
                }
            }
            if(!valid){
                continue;
            }
            rep(j, W){
                if(j == 0){
                    if(s.test(0)){
                        dp.at(i+1).at(0) += dp.at(i).at(1);
                    }
                    else{
                        dp.at(i+1).at(0) += dp.at(i).at(0);
                    }
                }
                else if(j < W-1){
                    if(s.test(j-1)){
                        dp.at(i+1).at(j) += dp.at(i).at(j-1);
                    }
                    else if(s.test(j)){
                        dp.at(i+1).at(j) += dp.at(i).at(j+1);
                    }
                    else{
                        dp.at(i+1).at(j) += dp.at(i).at(j);
                    }
                }
                else{
                    if(s.test(W-2)){
                        dp.at(i+1).at(W-1) += dp.at(i).at(W-2);
                    }
                    else{
                        dp.at(i+1).at(W-1) += dp.at(i).at(W-1);
                    }
                }
            }
        }
    }
    cout << dp.at(H).at(K-1) << endl;
}