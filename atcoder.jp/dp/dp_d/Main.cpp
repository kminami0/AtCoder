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

vector<vector<ll>> dp(101, vector<ll>(100001, 0));
//dp.at(i).at(j)は始めのi個まで使って重さがj以下になる最大価値

int main(){
  ll N, W;
  cin >> N >> W;
  vector<ll> w(N), v(N);
  rep(i, N){
    cin >> w.at(i) >> v.at(i);
  }
  rep(i, N){
    rep(j, W+1){
      if(j >= w.at(i)){
        dp.at(i+1).at(j) = max(dp.at(i).at(j), dp.at(i).at(j-w.at(i))+v.at(i));
      }
      else{
        dp.at(i+1).at(j) = dp.at(i).at(j);
      }
    }
  }
  cout << dp.at(N).at(W) << endl;
}