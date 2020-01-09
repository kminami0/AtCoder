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
  int n, k;
  cin >> n >> k;
  vector<string> a(n);
  rep(i, n){
    cin >> a.at(i);
  }
  set<int> S;
  sort(all(a));
  do{
    string b = "";
    rep(i, k){
      b += a.at(i);
    }
    int c = stoi(b);
    S.insert(c);
  } while(next_permutation(all(a)));
  cout << S.size() << endl;
}