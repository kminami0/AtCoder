#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
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

vector<vector<ll>> dp(100, vector<ll>(21, 0));
// dp.at(i).at(j)はi個の数字を使って値がjになるJOI君でも理解できる式の個数

int main(){
  ll N;
  cin >> N;
  vector<ll> a(N);
  rep(i, N){
    cin >> a.at(i);
  }
  dp.at(1).at(a.at(0)) = 1;
  rep2(i, 1, N-1){
    rep(j, 21){
      if(j + a.at(i) > 20){
        break;
      }
      dp.at(i+1).at(j + a.at(i)) += dp.at(i).at(j);
    }
    rep(j, 21){
      if(j - a.at(i) < 0){
        continue;
      }
      dp.at(i+1).at(j - a.at(i)) += dp.at(i).at(j);
    }
  }
  cout << dp.at(N-1).at(a.at(N-1)) << endl;
}