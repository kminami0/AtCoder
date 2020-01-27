#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000000
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

vector<vector<ll>> dp(1001, vector<ll>(20000, INF));

int main(){
  ll H, N;
  cin >> H >> N;
  vector<ll> A(N), B(N);
  rep(i, N){
    cin >> A.at(i) >> B.at(i);
  }
  ll a = 0;
  rep(i, N){
    chmax(a, A.at(i));
  }
  rep(i, N+1){
    dp.at(i).at(0) = 0;
  }
  ll ans = INF;
  rep(i, N){
    rep(j, H+a){
      chmin(dp.at(i+1).at(j), dp.at(i).at(j));
      if(j >= A.at(i)){
        chmin(dp.at(i+1).at(j), dp.at(i+1).at(j-A.at(i))+B.at(i));
      }
      if(j >= H){
        chmin(ans, dp.at(i+1).at(j));
      }
    }
  }
  cout << ans << endl;
}