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

int main(){
  ll N;
  cin >> N;
  vector<ll> p(N);
  rep(i, N){
    cin >> p.at(i);
  }
  vector<vector<bool>> dp(N+1, vector<bool>(10001));
  rep(i, N+1){
    dp.at(i).at(0) = true;
  }
  rep(i, N){
    rep(j, 10001){
      if(j >= p.at(i)){
        dp.at(i+1).at(j) = dp.at(i).at(j-p.at(i)) || dp.at(i).at(j);
      }
      else{
        dp.at(i+1).at(j) = dp.at(i).at(j);
      }
    }
  }
  ll ans = 0;
  rep(j, 10001){
    if(dp.at(N).at(j)){
      ans++;
    }
  }
  cout << ans << endl;
}