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
  int N;
  cin >> N;
  vector<int> P(N), Q(N);
  rep(i, N){
    cin >> P.at(i);
  }
  rep(i, N){
    cin >> Q.at(i);
  }
  vector<int> R(N);
  rep(i, N){
    R.at(i) = i+1;
  }
  int a = 0;
  int b = 0;
  int c = 0;
  bool mtP = true;
  bool mtQ = true;
  sort(all(R));
  do {
    rep(i, N){
      if(mtP){
        if(P.at(i) != R.at(i)){
          mtP = false;
        }
      }
      if(mtQ){
        if(Q.at(i) != R.at(i)){
          mtQ = false;
        }
      }
    }
    if(mtP){
      a = c;
    }
    if(mtQ){
      b = c;
    }
    mtP = true;
    mtQ = true;
    c++;
  } while (next_permutation(all(R)));
  cout << abs(a-b) << endl;
}