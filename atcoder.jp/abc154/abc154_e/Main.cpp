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

vector<vector<vector<ll>>> dp(102, vector<vector<ll>>(4, vector<ll>(2)));

int main(){
  string N;
  int K;
  cin >> N >> K;
  dp.at(0).at(0).at(0) = 1;
  rep(i, sz(N)){
    rep(j, K+1){
      rep(k, 2){
        rep(d, (k ? 9 : N.at(i)-'0')+1){
          if(d != 0 && j == K){
            break;
          }
          if(d != 0){
            dp.at(i+1).at(j+1).at(k || (d < N.at(i)-'0')) += dp.at(i).at(j).at(k);
          }
          else{
            dp.at(i+1).at(j).at(k || (d < N.at(i)-'0')) += dp.at(i).at(j).at(k);
          }
        }
      }
    }
  }
  cout << dp.at(sz(N)).at(K).at(0)+dp.at(sz(N)).at(K).at(1) << endl;
}