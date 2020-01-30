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
  int W, N, K;
  cin >> W >> N >> K;
  vector<int> A(N), B(N);
  rep(i, N){
    cin >> A.at(i) >> B.at(i);
  }
  vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(W+1, vector<int>(K+1)));
  rep(i, N){
    rep(j, W+1){
      rep(k, K+1){
        if(j >= A.at(i) && k >= 1){
          dp.at(i+1).at(j).at(k) = max(dp.at(i).at(j-A.at(i)).at(k-1)+B.at(i), dp.at(i).at(j).at(k));
        }
        else if(j < A.at(i)){
          dp.at(i+1).at(j).at(k) = dp.at(i).at(j).at(k);
        }
      }
    }
  }
  cout << dp.at(N).at(W).at(K) << endl;
}