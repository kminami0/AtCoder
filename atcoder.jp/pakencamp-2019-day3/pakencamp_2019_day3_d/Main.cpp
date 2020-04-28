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

vector<vector<ll>> dp(999, vector<ll>(3, 0));

int main(){
  ll N;
  cin >> N;
  vector<string> S(5);
  rep(i, 5){
    cin >> S.at(i);
  }
  vector<vector<ll>> npc(N, vector<ll>(3, 5));
  rep(i, N){
    rep(j, 5){
      if(S.at(j).at(i) == 'R'){
        npc.at(i).at(0)--;
      }
      if(S.at(j).at(i) == 'B'){
        npc.at(i).at(1)--;
      }
      if(S.at(j).at(i) == 'W'){
        npc.at(i).at(2)--;
      }
    }
  }
  rep(i, 3){
    dp.at(0).at(i) = npc.at(0).at(i);
  }
  rep(i, N-1){
    dp.at(i+1).at(0) = npc.at(i+1).at(0) + min(dp.at(i).at(1), dp.at(i).at(2));
    dp.at(i+1).at(1) = npc.at(i+1).at(1) + min(dp.at(i).at(0), dp.at(i).at(2));
    dp.at(i+1).at(2) = npc.at(i+1).at(2) + min(dp.at(i).at(0), dp.at(i).at(1));
  }
  cout << min(dp.at(N-1).at(0), min(dp.at(N-1).at(1), dp.at(N-1).at(2))) << endl;
}