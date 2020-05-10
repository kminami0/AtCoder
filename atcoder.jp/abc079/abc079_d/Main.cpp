#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14 100兆
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
  ll H, W;
  cin >> H >> W;
  vector<vector<ll>> c(10, vector<ll>(10));
  rep(i, 10){
    rep(j, 10){
      cin >> c.at(i).at(j);
    }
  }
  vector<vector<ll>> A(H, vector<ll>(W));
  rep(i, H){
    rep(j, W){
      cin >> A.at(i).at(j);
    }
  }
  rep(k, 10){
    rep(i, 10){
      rep(j, 10){
        chmin(c.at(i).at(j), c.at(i).at(k)+c.at(k).at(j));
      }
    }
  }
  ll ans = 0;
  rep(i, H){
    rep(j, W){
      if(A.at(i).at(j) == -1){
        continue;
      }
      ans += c.at(A.at(i).at(j)).at(1);
    }
  }
  cout << ans << endl;
}