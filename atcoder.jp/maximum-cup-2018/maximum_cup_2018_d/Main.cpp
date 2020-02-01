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

vector<vector<int>> dp(10001, vector<int>(1000));

int main(){
  int N, M, L, X;
  cin >> N >> M >> L >> X;
  vector<int> a(N);
  rep(i, N){
    cin >> a.at(i);
  }
  rep(i, 999){
    dp.at(0).at(i+1) = INF;
  }
  rep(i, N){
    rep(j, M){
      int p = j-a.at(i);
      while(p < 0){
        p += M;
      }
      dp.at(i+1).at(j) = min(dp.at(i).at(p%M)+min(a.at(i)/(M-j), 1)+max((a.at(i)-(M-j))/M, 0), dp.at(i).at(j));
    }
  }
  if(dp.at(N).at(L) < X){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}