#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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
//浮動小数点はなるべく使うな、powも気をつけろ

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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> B(M);
    rep(i, M) cin >> B.at(i);
    sort(all(A));
    reverse(all(A));
    sort(all(B));
    reverse(all(B));
    rep(i, N-1){
        if(A.at(i) == A.at(i+1)){
            cout << 0 << '\n';
            return 0;
        }
    }
    rep(i, M-1){
        if(B.at(i) == B.at(i+1)){
            cout << 0 << '\n';
            return 0;
        }
    }
    ll p = 1;
    ll q = 1;
    mint ans = 1;
    if(A.at(0) != N*M || B.at(0) != N*M){
        cout << 0 << '\n';
        return 0;
    }
	A.emplace_back(0);
	B.emplace_back(0);
    rep2(i, 1, N*M){
        if(A.at(p) == N*M-i && B.at(q) == N*M-i){
            p++;
            q++;
        }
        else if(A.at(p) == N*M-i && B.at(q) < N*M-i){
            p++;
            ans *= q;
        }
        else if(A.at(p) < N*M-i && B.at(q) == N*M-i){
            q++;
            ans *= p;
        }
        else{
          ans *= p*q-i;
        }
    }
    cout << ans << '\n';
}