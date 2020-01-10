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
  int m;
  cin >> m;
  int ans = 0;
  int res;
  ans += (1000 - m) / 500;
  res = (1000 - m) % 500;
  ans += res / 100;
  res %= 100;
  ans += res / 50;
  res %= 50;
  ans += res / 10;
  res %= 10;
  ans += res / 5;
  res %= 5;
  ans += res;
  cout << ans << endl;
}