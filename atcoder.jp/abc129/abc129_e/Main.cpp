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
    string L;
    cin >> L;
    vector<vector<mint>> dp(sz(L)+1, vector<mint>(2, 0));
    //桁DPを行う
    //dp.at(i).at(0)は上からi桁まで決めたとき、a+bがL未満であると確定していない取り方
    //dp.at(i).at(1)は上からi桁まで決めたとき、a+bがL未満であると確定している取り方
    //a+b = a xor bとなるのは、aとbを2進表記したとき1である箇所が重複していない場合
    //よってa+bの上からi桁目が0となるのはa,bの上からi桁目が0の場合
    //a+bの上からi桁目が1となるのはa,bの上からi桁目は一方が1、他方が0の場合
    dp.at(0).at(0) = 1;
    rep(i, sz(L)){
        ll D = L.at(i) - '0';
        rep(j, 2){
            rep(d, (j ? 2 : D+1)){
                if(d == 0){
                    dp.at(i+1).at(j || (d<D)) += dp.at(i).at(j); 
                }
                else{
                    dp.at(i+1).at(j || (d<D)) += dp.at(i).at(j) * 2; 
                }
            }
        }
    }
    cout << dp.at(sz(L)).at(0) + dp.at(sz(L)).at(1) << endl;
}