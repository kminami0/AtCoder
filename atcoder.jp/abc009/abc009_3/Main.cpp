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

int unmatch(string s, string t){
  int ans = 0;
  int p = 0;
  while(p < 26){
    char i = 'a' + p;
    int cnts = 0;
    int cntt = 0;
    rep(j, sz(s)){
      if(s.at(j) == i){
        cnts++;
      }
      if(t.at(j) == i){
        cntt++;
      }
    }
    ans += min(cnts, cntt);
    p++;
  }
  return sz(s) - ans;
}

int main(){
  int N, K;
  string S;
  cin >> N >> K >> S;
  string T = "";
  string U = S;
  sort(all(U));
  int cnt = 0;
  rep(i, N){
    rep(j, sz(U)){
      T += U.at(j);
      U.erase(j, 1);
      cnt = 0;
      rep(k, i+1){
        if(S.at(k) != T.at(k)){
          cnt++;
        }
      }
      if(unmatch(S.substr(i+1), U) <= K - cnt){
        break;
      }
      U += T.at(sz(T)-1);
      sort(all(U));
      T.erase(sz(T)-1);
    }
  }
  cout << T << endl;
}