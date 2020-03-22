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

int main(){
  string S;
  cin >> S;
  ll N = sz(S);
  string T = S;
  reverse(all(T));
  string U = S.substr(0, (N-1)/2);
  string V = S.substr((N+1)/2, (N-1)/2);
  string W = U;
  reverse(all(W));
  string X = V;
  reverse(all(X));
  if(S == T && U == W && V == X){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}