#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
#define EPSILON 1e-14
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

vector<bool> fbool(1000001, false);
vector<mint> fval(1000001);
vector<bool> gbool(1000001, false);
vector<mint> gval(1000001);

mint mpow(mint x, ll y){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    mint a = mpow(x, y / 2);
    return a * a;
  }
  else{
    mint a = mpow(x, y / 2);
    return a * a * x;
  }
}

mint g(ll N, ll D){
    if(gbool.at(N)){
        return gval.at(N);
    }
    if(N == 1){
        gbool.at(N) = true;
        gval.at(N) = 0;
        return 0;
    }
    if(D < N-1){
        gbool.at(N) = true;
        gval.at(N) = g(N-1, D);
        return g(N-1, D);
    }
    if(D-(N-1) > N-1){
        gbool.at(N) = true;
        gval.at(N) = 0;
        return 0;
    }
    if(N-1 == D-(N-1)){
        gbool.at(N) = true;
        gval.at(N) = g(N-1, D) + mpow(2, N-1) * mpow(2, N-1) / 2;
        return g(N-1, D) + mpow(2, N-1) * mpow(2, N-1) / 2;
    }
    if(D-(N-1) == 0){
        gbool.at(N) = true;
        gval.at(N) = g(N-1, D) + mpow(2, N-1) * 2;
        return g(N-1, D) + mpow(2, N-1) * 2;
    }
    gbool.at(N) = true;
    gval.at(N) = g(N-1, D) + mpow(2, N-1) * mpow(2, D-(N-1));
    return g(N-1, D) + mpow(2, N-1) * mpow(2, D-(N-1));
}

mint f(ll N, ll D){
    if(fbool.at(N)){
        return fval.at(N);
    }
    if(N == 1){
        fbool.at(N) = true;
        fval.at(N) = 0;
        return 0;
    }
    fbool.at(N) = true;
    fval.at(N) = f(N-1, D) * 2 + g(N, D);
    return f(N-1, D) * 2 + g(N, D);
}

int main()
{
    ll N, D;
    cin >> N >> D;
    cout << f(N, D) << '\n';
}