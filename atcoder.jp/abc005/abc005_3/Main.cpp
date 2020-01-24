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
  int T, N;
  cin >> T >> N;
  vector<int> A(N);
  rep(i, N){
    cin >> A.at(i);
  }
  int M;
  cin >> M;
  vector<int> B(M);
  rep(i, M){
    cin >> B.at(i);
  }
  int tako = 0;
  bool psb = false;
  rep(i, M){
    if(tako >= N){
      break;
    }
    if(A.at(tako) <= B.at(i) && B.at(i) <= A.at(tako) + T){
      tako++;
    }
    else{
      tako++;
      i--;
    }
    if(i == M-1){
      psb = true;
    }
  }
  if(psb){
    cout << "yes" << endl;
  }
  else{
    cout << "no" << endl;
  }
}