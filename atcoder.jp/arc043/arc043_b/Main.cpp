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
    vector<ll> D(N);
    rep(i, N) cin >> D.at(i);
    D.push_back(0);
    D.push_back(INF);
    sort(all(D)); //難易度順にソートする
    vector<ll> A(N); //A.at(i)はi+1問目の2倍以上の難易度の問題の数
    vector<ll> B(N); //B.at(i)はi+1問目の半分以下の難易度の問題の数
    vector<ll> C(N); //C.at(i)はi+1問目の2倍以上の難易度を持つ最初の問題の位置
    rep(i, N){
        ll l = 0;
        ll r = N+1;
        // D.at(l) < 2*D.at(i+1) <= D.at(r)
        while(r-l > 1){
            ll c = (l+r) / 2;
            if(D.at(c) < 2*D.at(i+1)){
                l = c;
            }
            else{
                r = c;
            }
        }
        A.at(i) = N+1-r;
        C.at(i) = r;
        l = 0;
        r = N+1;
        // 2*D.at(l) <= D.at(i+1) < 2*D.at(r)
        while(r-l > 1){
            ll c = (l+r) / 2;
            if(2*D.at(c) <= D.at(i+1)){
                l = c;
            }
            else{
                r = c;
            }
        }
        B.at(i) = l;
    }
    vector<ll> Asum(N+1, 0);
    rep(i, N){
        Asum.at(i+1) = Asum.at(i) + A.at(i);
    }
    mint ans = 0;
    rep(i, N){
        ans += B.at(i) * (Asum.at(N) - Asum.at(C.at(i)-1));
    }
    cout << ans << endl;
}