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
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, n){
    cin >> a.at(i) >> b.at(i);
  }
  vector<ll> paints(1000002, 0);
  rep(i, n){
    paints.at(a.at(i))++;
    paints.at(b.at(i)+1)--;
  }
  rep(i, 1000001){
    paints.at(i+1) += paints.at(i);
  }
  ll ans = 0;
  rep(i, 1000002){
    chmax(ans, paints.at(i));
  }
  cout << ans << endl;
}