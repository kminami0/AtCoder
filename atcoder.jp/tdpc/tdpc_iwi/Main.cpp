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

vector<vector<int>> dp(301, vector<int>(301));
// dp.at(L).at(R)はL文字目からR-1文字目の部分文字列に対する解
vector<vector<bool>> dp2(301, vector<bool>(301, false));
// dp2.at(L).at(R)はL文字目からR-1文字目までを消せるかどうか

int main(){
  string s;
  cin >> s;
  rep(i, sz(s)-2){
    if(s.substr(i, 3) == "iwi"){
      dp.at(i).at(i+3) = 1;
      dp2.at(i).at(i+3) = true;
    }
  }
  rep(b, sz(s)+1){
    for (int L = sz(s); L >= 0; L--){
      int R = L + b;
      if(R > sz(s)){
        continue;
      }
      if(L+1 <= R-2){
        if(s.at(L) == 'i' && s.substr(R-2, 2) == "wi" && dp2.at(L+1).at(R-2)){
          chmax(dp.at(L).at(R), dp.at(L+1).at(R-2) + 1);
          dp2.at(L).at(R) = true;
        }
      }
      if(L+2 <= R-1){
        if(s.substr(L, 2) == "iw" && s.at(R-1) == 'i' && dp2.at(L+2).at(R-1)){
          chmax(dp.at(L).at(R), dp.at(L+2).at(R-1) + 1);
          dp2.at(L).at(R) = true;
        }
      }
      rep2(i, L, R+1){
        chmax(dp.at(L).at(R), dp.at(L).at(i)+dp.at(i).at(R));
        if(dp2.at(L).at(i) && dp2.at(i).at(R)){
          dp2.at(L).at(R) = true;
        }
      }
    }
  }
  cout << dp.at(0).at(sz(s)) << endl;
}