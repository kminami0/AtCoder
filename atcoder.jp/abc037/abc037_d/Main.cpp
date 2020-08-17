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

vector<vector<mint>> dp(1001, vector<mint>(1001, 0));
vector<vector<ll>> a(1002, vector<ll>(1002));
vector<vector<bool>> used(1001, vector<bool>(1001, false));

mint routes(ll x, ll y){
    if(used.at(x).at(y)){
        return dp.at(x).at(y);
    }
    mint tmp = 1;
    if(a.at(x-1).at(y) > a.at(x).at(y)){
        tmp += routes(x-1, y);
    }
    if(a.at(x+1).at(y) > a.at(x).at(y)){
        tmp += routes(x+1, y);
    }
    if(a.at(x).at(y-1) > a.at(x).at(y)){
        tmp += routes(x, y-1);
    }
    if(a.at(x).at(y+1) > a.at(x).at(y)){
        tmp += routes(x, y+1);
    }
    used.at(x).at(y) = true;
    dp.at(x).at(y) = tmp;
    return tmp;
}

int main()
{
    ll H, W;
    cin >> H >> W;
    rep(i, H){
        rep(j, W){
            cin >> a.at(i+1).at(j+1);
        }
    }
    rep(i, H+2){
        if(i == 0 || i == H+1){
            rep(j, W+2){
                a.at(i).at(j) = 0;
            }
        }
        else{
            a.at(i).at(0) = 0;
            a.at(i).at(W+1) = 0;
        }
    }
    mint ans = 0;
    rep(i, H){
        rep(j, W){
            ans += routes(i+1, j+1);
//            cout << i+1 << " " << j+1 << " " << routes(i+1, j+1) << endl;
        }
    }
    cout << ans << endl;
}