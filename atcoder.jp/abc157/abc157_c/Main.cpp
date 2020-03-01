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
  ll N, M;
  cin >> N >> M;
  vector<ll> s(M), c(M);
  rep(i, M){
    cin >> s.at(i) >> c.at(i);
  }
  vector<ll> cond(N+1, -1);
  rep(i, M){
    if(cond.at(s.at(i)) == -1){
      cond.at(s.at(i)) = c.at(i);
    }
    else{
      if(cond.at(s.at(i)) != c.at(i)){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  string ans = "";
  if(N == 1 && (cond.at(1) == -1 || cond.at(1) == 0)){
    cout << 0 << endl;
    return 0;
  }
  if(N == 1){
    cout << cond.at(1) << endl;
    return 0;
  }
  rep(i, N){
    if(i == 0 && cond.at(i+1) == 0){
      cout << -1 << endl;
      return 0;
    }
    else if(i == 0 && cond.at(i+1) == -1){
      ans += 1 + '0';
    }
    else if(cond.at(i+1) == -1 || cond.at(i+1) == 0){
      ans += 0 + '0';
    }
    else{
      ans += cond.at(i+1) + '0';
    }
  }
  cout << ans << endl;
}