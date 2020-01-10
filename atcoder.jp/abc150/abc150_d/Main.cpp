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
  int64_t N, M;
  cin >> N >> M;
  vector<int64_t> a(N);
  rep(i, N){
    cin >> a.at(i);
  }
  sort(all(a));
  int64_t g = a.at(N-1) / 2;
  bool fnd = false;
  while(g <= M){
    rep(i, N){
      if(g % a.at(i) != a.at(i) / 2){
        break;
      }
      if(i == N-1){
        fnd = true;
      }
    }
    if(fnd){
      break;
    }
    g += a.at(N-1);
  }
  if(g <= M){
    cout << (M - g) / (2 * g) + 1 << endl;
  }
  else{
    cout << 0 << endl;
  }
}