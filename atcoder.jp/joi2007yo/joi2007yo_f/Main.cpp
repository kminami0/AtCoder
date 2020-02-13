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

vector<vector<int>> dp(17, vector<int>(17));

int main(){
  int a, b, n;
  cin >> a >> b >> n;
  vector<int> x(n), y(n);
  set<P> uc;
  rep(i, n){
    cin >> x.at(i) >> y.at(i);
    uc.insert(make_pair(x.at(i), y.at(i)));
  }
  dp.at(a).at(b) = 1;
  rep(i, a){
    rep(j, b){
      if(i == 0 && j == 0){
        continue;
      }
      else if(i == 0){
        if(uc.count(make_pair(a, b-j+1))){
          dp.at(a).at(b-j) = 0;
        }
        else{
          dp.at(a).at(b-j) = dp.at(a).at(b-j+1);
        }
      }
      else if(j == 0){
        if(uc.count(make_pair(a-i+1, b))){
          dp.at(a-i).at(b) = 0;
        }
        else{
          dp.at(a-i).at(b) = dp.at(a-i+1).at(b);
        }
      }
      else{
        if(uc.count(make_pair(a-i, b-j+1))){
          if(uc.count(make_pair(a-i+1, b-j))){
            dp.at(a-i).at(b-j) = 0;
          }
          else{
            dp.at(a-i).at(b-j) = dp.at(a-i+1).at(b-j);
          }
        }
        else if(uc.count(make_pair(a-i+1, b-j))){
          dp.at(a-i).at(b-j) = dp.at(a-i).at(b-j+1);
        }
        else{
          dp.at(a-i).at(b-j) = dp.at(a-i+1).at(b-j) + dp.at(a-i).at(b-j+1);
        }
      }
    }
  }
  cout << dp.at(1).at(1) << endl;
}