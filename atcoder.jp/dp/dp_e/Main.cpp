#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000009
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

vector<vector<ll>> dp(101, vector<ll>(100001, INF*2));
//dp.at(i).at(j)は始めのi個まで使って価値がj以上になる最小の重さ

int main(){
  ll N, W;
  cin >> N >> W;
  vector<ll> w(N), v(N);
  rep(i, N){
    cin >> w.at(i) >> v.at(i);
  }
  rep(i, N){
    rep(j, 100001){
      if(j > v.at(i)){
        dp.at(i+1).at(j) = min(dp.at(i).at(j), dp.at(i).at(j-v.at(i))+w.at(i));
      }
      else{
        dp.at(i+1).at(j) = min(dp.at(i).at(j), w.at(i));
      }
    }
  }
  ll ans = 0;
  rep(i, 100001){
    if(dp.at(N).at(i) <= W){
      ans = i;
    }
  }
  cout << ans << endl;
}