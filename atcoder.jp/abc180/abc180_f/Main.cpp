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

vector<mint> fac(2000003, 1);
void calc(int n){
  rep(i, n){
    fac.at(i+1) = fac.at(i) * (i+1);
  }
  return;
}

mint mcom(int r, int c){ // (r+c)!/(r!c!)
  mint a = fac.at(r+c);
  mint b = fac.at(r);
  mint d = fac.at(c);
  mint ans = a / (b * d);
  return ans;
}

int main()
{
    int N, M, L;
    cin >> N >> M >> L;
    calc(310);
    vector<vector<mint>> dp0(N+1, vector<mint>(M+1, 0));
    vector<vector<mint>> dp1(N+1, vector<mint>(M+1, 0));
    //dp0.at(i).at(j).at(k)はi頂点j辺で最大連結成分のサイズがL以下で自己ループを持たず全ての頂点の次数が高々2のグラフの数
    //dp1.at(i).at(j).at(k)はi頂点j辺で最大連結成分のサイズがL-1以下で自己ループを持たず全ての頂点の次数が高々2のグラフの数
    dp0[0][0] = 1;
    dp1[0][0] = 1;
    vector<vector<mint>> modcomb(310, vector<mint>(310, 0));
    vector<vector<mint>> modcomb2(310, vector<mint>(310, 0));
    vector<vector<mint>> modcomb3(310, vector<mint>(310, 0));
    rep(i, 310){
      rep(j, 310){
        modcomb[i][j] = mcom(i, j);
        modcomb2[i][j] = modcomb[i][j] * fac[i+1] / 2;
        modcomb3[i][j] = modcomb[i][j] * fac[i] / 2;
      }
    }
    rep(i, N+1){
      rep(j, M+1){
        rep2(k, 1, L+1){
          if(i+k > N || j+k-1 > M){
            break;
          }
          if(k == 1){
            dp0[i+k][j+k-1] += dp0[i][j] * modcomb[k-1][N-i-k];
          }
          else{
            dp0[i+k][j+k-1] += dp0[i][j] * modcomb2[k-1][N-i-k];
          }
          if(j+k > M){
            break;
          }
          if(k == 1){
            continue;
          }
          if(k == 2){
            dp0[i+k][j+k] += dp0[i][j] * modcomb[k-1][N-i-k];
          }
          else{
            dp0[i+k][j+k] += dp0[i][j] * modcomb3[k-1][N-i-k];
          }
        }
      }
    }
    rep(i, N+1){
      rep(j, M+1){
        rep2(k, 1, L){
          if(i+k > N || j+k-1 > M){
            break;
          }
          if(k == 1){
            dp1[i+k][j+k-1] += dp1[i][j] * modcomb[k-1][N-i-k];
          }
          else{
            dp1[i+k][j+k-1] += dp1[i][j] * modcomb2[k-1][N-i-k];
          }
          if(j+k > M){
            break;
          }
          if(k == 1){
            continue;
          }
          if(k == 2){
            dp1[i+k][j+k] += dp1[i][j] * modcomb[k-1][N-i-k];
          }
          else{
            dp1[i+k][j+k] += dp1[i][j] * modcomb3[k-1][N-i-k];
          }
        }
      }
    }
    cout << dp0[N][M] - dp1[N][M] << endl;
}