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

vector<mint> dp(200009, 0);
//dp.at(i)でiだけ進む方法の数
vector<mint> S(200009, 0);
//S.at(i)で0~i-1だけ進む方法の数の和

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> L(K), R(K);
    rep(i, K){
        cin >> L.at(i) >> R.at(i);
    }
    sort(all(L));
    sort(all(R));
    dp.at(0) = 1;
    S.at(1) = 1;
    rep2(i, 1, N+1){
        ll pos = -1;
        // L.at(pos) <= i < L.at(pos+1)
        if(K == 1){
            if(L.at(0) <= i){
                pos = 0;
            }
        }
        rep(j, K-1){
            if(L.at(j) <= i && i < L.at(j+1)){
                pos = j;
                break;
            }
            if(j == K-2){
                if(L.at(K-1) <= i){
                    pos = K-1;
                    break;
                }
                else{
                    pos = -1;
                    break;
                }
            }
        }
        rep(j, pos+1){
            if(R.at(j) <= i){
                dp.at(i) += S.at(i-L.at(j)+1) - S.at(i-R.at(j));
            }
            else{
                dp.at(i) += S.at(i-L.at(j)+1);
            }
        }
        S.at(i+1) = S.at(i) + dp.at(i);
    }
//    rep(i, N+1){
//        cout << dp.at(i) << endl;
//    }
    cout << dp.at(N-1) << endl;
}