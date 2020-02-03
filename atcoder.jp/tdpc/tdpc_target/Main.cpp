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

vector<int> dp(100001, -1 * INF);

int main(){
  int N;
  cin >> N;
  vector<int> x(N), R(N);
  rep(i, N){
    cin >> x.at(i) >> R.at(i);
  }
  vector<P> C(N);
  rep(i, N){
    C.at(i) = make_pair(x.at(i)+R.at(i), x.at(i)-R.at(i));
  }
  sort(all(C));
  dp.at(0) = C.at(0).second;
  int l = 0;
  int r = N;
  rep(i, N-1){
    if(C.at(i+1).second >= dp.at(0)){
      dp.at(0) = C.at(i+1).second;
    }
    else{
      l = 0;
      r = N;
      while(r-l>1){
        if(dp.at((l+r)/2) <= C.at(i+1).second){
          r = (l+r)/2;
        }
        else{
          l = (l+r)/2;
        }
      }
      dp.at(r) = C.at(i+1).second;
    }
  }
  l = 0;
  r = N;
  while(r-l>1){
    if(dp.at((l+r)/2) > -1 * INF){
      l = (l+r)/2;
    }
    else{
      r = (l+r)/2;
    }
  }
  cout << l+1 << endl;
}