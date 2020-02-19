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

vector<vector<int>> dp(1000003, vector<int>(2, INF));
//dp.at(i).at(j)は繰り下がりがjのときにN%10^i円払う最小値

int main(){
  string N;
  cin >> N;
  vector<ll> s(sz(N)+1);
  rep(i, sz(N)){
    s.at(i+1) = s.at(i) + N.at(i) - '0';
  }
  dp.at(0).at(0) = 0;
  rep(i, sz(N)){
    rep(j, 2){
      rep(d, 10){
        if(j == 0){
          if(d < N.at(sz(N)-1-i)-'0'){
            chmin(dp.at(i+1).at(1), d + 10+d-(N.at(sz(N)-1-i)-'0') + dp.at(i).at(0) + 1);
          }
          else{
            chmin(dp.at(i+1).at(0), d + d-(N.at(sz(N)-1-i)-'0') + dp.at(i).at(0));
          }
        }
        else{
          if(d-1 < N.at(sz(N)-1-i)-'0'){
            chmin(dp.at(i+1).at(1), d-1 + 10+d-1-(N.at(sz(N)-1-i)-'0') + dp.at(i).at(1) + 1);
          }
          else{
            chmin(dp.at(i+1).at(0), d-1 + d-1-(N.at(sz(N)-1-i)-'0') + dp.at(i).at(1));
          }
        }
      }
    }
  }
  cout << min(dp.at(sz(N)).at(0), dp.at(sz(N)).at(1)) << endl;
}