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

vector<ll> dp(30002, INF);

int main(){
  ll N;
  cin >> N;
  vector<ll> c(N);
  rep(i, N){
    cin >> c.at(i);
  }
  dp.at(0) = 0;
  rep(i, N){
    ll l = 0;
    ll r = N+1;
    // dp.at(l) < c.at(i) <= dp.at(r)
    while(r-l>1){
      ll ct = (l+r)/2;
      if(dp.at(ct) < c.at(i)){
        l = ct;
      }
      else{
        r = ct;
      }
    }
    dp.at(r) = c.at(i);
  }
  ll l = 0;
  ll r = N+1;
  while(r-l>1){
    ll ct = (l+r)/2;
    if(dp.at(ct) < INF){
      l = ct;
    }
    else{
      r = ct;
    }
  }
  cout << N - l << endl;
}