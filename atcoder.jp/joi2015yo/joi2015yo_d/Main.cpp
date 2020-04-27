#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14 100兆
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

vector<vector<ll>> dp(1001, vector<ll>(1001, INF));
//dp.at(i).at(j)はi日目の終わりに都市jにいるときの最小疲労度

int main(){
  ll N, M;
  cin >> N >> M;
  vector<ll> D(N), C(M);
  rep(i, N){
    cin >> D.at(i);
  }
  rep(i, M){
    cin >> C.at(i);
  }
  rep(i, M+1){
    dp.at(i).at(0) = 0;
  }
  rep(i, M){
    rep(j, N){
      dp.at(i+1).at(j+1) = min(dp.at(i).at(j+1), dp.at(i).at(j)+D.at(j)*C.at(i));
    }
  }
  cout << dp.at(M).at(N) << endl;
}