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
    ll N;
    cin >> N;
    vector<ll> T(N);
    rep(i, N) cin >> T.at(i);
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<pair<ll, ll>> h(N);
    rep(i, N){
        if(i == 0 || T.at(i) > T.at(i-1)){
            h.at(i) = {T.at(i), T.at(i)};
        }
        else{
            h.at(i) = {1, T.at(i)};
        }
    }
    rep(i, N){
        if(i == N-1 || A.at(i) > A.at(i+1)){
            if(A.at(i) < h.at(i).first || h.at(i).second < A.at(i)){
                cout << 0 << endl;
                return 0;
            }
            else{
                h.at(i) = {A.at(i), A.at(i)};
            }
        }
        else{
            if(A.at(i) < h.at(i).first){
                cout << 0 << endl;
                return 0;
            }
            else{
                chmin(h.at(i).second, A.at(i));
            }
        }
    }
    mint ans = 1;
    rep(i, N){
        ans *= h.at(i).second - h.at(i).first + 1;
    }
    cout << ans << endl;
}