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

vector<int> dp(100001, INF);

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N){
    cin >> a.at(i);
  }
  dp.at(0) = a.at(0);
  rep(i, N-1){
    if(a.at(i+1) <= dp.at(0)){
      dp.at(0) = a.at(i+1);
    }
    else{
      int l = 0;
      int r = 100000;
      while(r-l > 1){
        if(dp.at((l+r)/2) < a.at(i+1)){
          l = (l+r)/2;
        }
        else{
          r = (l+r)/2;
        }
      }
      dp.at(r) = a.at(i+1);
    }
  }
  int l = 0;
  int r = 100000;
  while(r-l > 1){
    if(dp.at((l+r)/2) < INF){
      l = (l+r)/2;
    }
    else{
      r = (l+r)/2;
    }
  }
  cout << l+1 << endl;
}