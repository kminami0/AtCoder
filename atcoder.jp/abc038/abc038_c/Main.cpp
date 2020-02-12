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
  int N;
  cin >> N;
  vector<int> a(N+1);
  rep(i, N){
    cin >> a.at(i);
  }
  a.at(N) = -1;
  ll tmp = 1;
  ll ans = 0;
  rep(i, N){
    if(a.at(i) < a.at(i+1)){
      tmp++;
    }
    else{
      ans += (tmp * (tmp+1)) / 2;
      tmp = 1;
    }
  }
  cout << ans << endl;
}