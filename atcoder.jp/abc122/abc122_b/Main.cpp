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
  ll ans = 0;
  rep(i, sz(S)){
    ll c = 0;
    rep2(j, i, sz(S)){
      if(S.at(j) == 'A' || S.at(j) == 'C' || S.at(j) == 'G' || S.at(j) == 'T'){
        c++;
      }
      else{
        break;
      }
    }
    chmax(ans, c);
  }
  cout << ans << endl;
}