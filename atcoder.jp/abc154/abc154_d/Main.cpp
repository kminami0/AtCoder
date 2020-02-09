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
  int N, K;
  cin >> N >> K;
  vector<int> p(N);
  rep(i, N){
    cin >> p.at(i);
  }
  int s = 0;
  int t = 0;
  int u = 0;
  rep(i, K){
    t += p.at(i);
  }
  s = t;
  rep(i, N-K){
    t -= p.at(i);
    t += p.at(i+K);
    if(chmax(s, t)){
      u = i+1;
    }
  }
  double ans = 0;
  rep(i, K){
    ans += (p.at(u+i)+1) / 2.0;
  }
  cout << fixed << setprecision(12);
  cout << ans << endl;
}