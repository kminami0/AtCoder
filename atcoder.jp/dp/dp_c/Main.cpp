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

vector<vector<ll>> dp(100000, vector<ll>(3, 0));
//dp.at(i).at(j)はi+1日目にjをしたときの最大幸福

int main(){
  ll N;
  cin >> N;
  vector<ll> a(N), b(N), c(N);
  rep(i, N){
    cin >> a.at(i) >> b.at(i) >> c.at(i);
  }
  dp.at(0).at(0) = a.at(0);
  dp.at(0).at(1) = b.at(0);
  dp.at(0).at(2) = c.at(0);
  rep(i, N-1){
    dp.at(i+1).at(0) = max(dp.at(i).at(1)+a.at(i+1), dp.at(i).at(2)+a.at(i+1));
    dp.at(i+1).at(1) = max(dp.at(i).at(0)+b.at(i+1), dp.at(i).at(2)+b.at(i+1));
    dp.at(i+1).at(2) = max(dp.at(i).at(0)+c.at(i+1), dp.at(i).at(1)+c.at(i+1));
  }
  cout << max(dp.at(N-1).at(0), max(dp.at(N-1).at(1), dp.at(N-1).at(2))) << endl;
}