#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
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
  int T;
  cin >> T;
  vector<string> S(T);
  rep(i, T){
    cin >> S.at(i);
  }
  vector<int> cnt(T, 0);
  rep(i, T){
    rep(j, sz(S.at(i))){
      if(S.at(i).substr(j, 5) == "tokyo" || S.at(i).substr(j, 5) == "kyoto"){
        cnt.at(i)++;
        j += 3;
      }
    }
  }
  rep(i, T){
    cout << cnt.at(i) << endl;
  }
}