#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
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
  ll N, X, Y;
  cin >> N >> X >> Y;
  X--;
  Y--;
  vector<ll> ans(N, 0);
  rep(i, N){
    rep2(j, i+1, N){
      ll d = 0;
      if(j < X){
        d = j-i;
      }
      else if(i < X && X <= j && j <= Y){
        d = min(j-i, X-i+1+Y-j);
      }
      else if(i < X && Y < j){
        d = X-i+1+j-Y;
      }
      else if(X <= i && j <= Y){
        d = min(j-i, i-X+1+Y-j);
      }
      else if(X <= i && i <= Y && Y < j){
        d = min(j-i, i-X+1+j-Y);
      }
      else{
        d = j-i;
      }
      ans.at(d)++;
    }
  }
  rep(i, N-1){
    cout << ans.at(i+1) << endl;
  }
}