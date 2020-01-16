#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
  string S7, T;
  cin >> S7 >> T;
  string ans = S7;
  int s = -1;
  rep(i, sz(S7)-sz(T)+1){
    rep(j, sz(T)){
      if(S7.at(i+j) != T.at(j) && S7.at(i+j) != '?'){
        break;
      }
      if(j == sz(T)-1){
        s = i;
      }
    }
  }
  if(s == -1){
    cout << "UNRESTORABLE" << endl;
  }
  else{
    rep(i, sz(T)){
      ans.at(s+i) = T.at(i);
    }
    rep(i, sz(ans)){
      if(ans.at(i) == '?'){
        ans.at(i) = 'a';
      }
    }
    cout << ans << endl;
  }
}