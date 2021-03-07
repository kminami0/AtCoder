#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define sz(v) v.size()

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
    string N;
    int K;
    cin >> N >> K;
    int a = sz(N);
    vector<set<char>> kind(sz(N)+1);
    rep(i, sz(N)){
        kind.at(i+1) = kind.at(i);
        kind.at(i+1).insert(N.at(i));
    }
    vector<vector<mint>> dp(a+1, vector<mint>(17, 0));
    dp[0][0] = 1;
    int D = isdigit(N[0]) ? N[0]-'0' : N[0]-'A'+10;
    dp[1][1] = D-1;
    rep2(i, 1, a){
        rep(j, 17){
            dp[i+1][j] += dp[i][j] * j;
            if(j >= 1){
                dp[i+1][j] += dp[i][j-1] * (17-j);
            }
        }
        int d = isdigit(N[i]) ? N[i]-'0' : N[i]-'A'+10;
        int b = sz(kind.at(i));
        rep(j, d){
            if(j < 10){
                if(kind.at(i).count(j+'0')){
                    dp[i+1][b] += 1;
                }
                else{
                    dp[i+1][b+1] += 1;
                }
            }
            else{
                if(kind.at(i).count(j-10+'A')){
                    dp[i+1][b] += 1;
                }
                else{
                    dp[i+1][b+1] += 1;
                }
            }
        }
        dp[i+1][1] += 15;
    }
    set<int> T;
    rep(i, a){
        T.insert(N[i]);
    }
    if(sz(T) == K){
        cout << dp[a][K]+1 << '\n';
    }
    else{
        cout << dp[a][K] << '\n';
    }
}