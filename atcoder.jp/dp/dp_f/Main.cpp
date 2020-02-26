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

vector<vector<ll>> dp(3001, vector<ll>(3001, 0));
//dp.at(i).at(j)はsの初めi文字とtの初めj文字のLCS長

int main(){
  string s, t;
  cin >> s >> t;
  rep(i, sz(s)){
    rep(j, sz(t)){
      if(s.at(i) == t.at(j)){
        dp.at(i+1).at(j+1) = dp.at(i).at(j)+1;
      }
      else{
        dp.at(i+1).at(j+1) = max(dp.at(i+1).at(j), dp.at(i).at(j+1));
      }
    }
  }
  string ans = "";
  int i = sz(s);
  int j = sz(t);
  while(i != 0 && j != 0){
    if(dp.at(i).at(j) == dp.at(i).at(j-1)){
      j--;
    }
    else if(dp.at(i).at(j) == dp.at(i-1).at(j)){
      i--;
    }
    else{
      ans.push_back(s.at(i-1));
      i--;
      j--;
    }
  }
  reverse(all(ans));
  cout << ans << endl;
}