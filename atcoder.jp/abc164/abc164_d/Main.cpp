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

ll pow2(ll a, ll b){
  if(b == 0){
    return 1;
  }
  if(b % 2 == 0){
    ll x = pow2(a, b/2);
    return (x * x) % 2019;
  }
  else{
    ll x = pow2(a, b/2);
    return (x * x * a) % 2019;
  }
}

int main(){
  string S;
  cin >> S;
  vector<ll> r(sz(S)+1, 0);
  rep(i, sz(S)){
    r.at(i+1) = ((S.at(sz(S)-i-1)-'0')*pow2(10, i)+ r.at(i)) % 2019;
  }
  vector<ll> c(2019);
  rep(i, sz(S)+1){
    c.at(r.at(i))++;
  }
  ll ans = 0;
  rep(i, 2019){
    ans += c.at(i)*(c.at(i)-1)/2;
  }
  cout << ans << endl;
}