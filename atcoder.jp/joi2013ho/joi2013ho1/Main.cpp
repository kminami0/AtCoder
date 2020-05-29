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
  ll N;
  cin >> N;
  if(N <= 2){
    cout << N << endl;
    return 0;
  }
  vector<ll> alt(N, 0);
  ll p = 0;
  ll prev = -1;
  rep(i, N){
    ll light;
    cin >> light;
    if(light != prev){
      alt.at(p)++;
    }
    else{
      p++;
      alt.at(p)++;
    }
    prev = light;
  }
  ll ans = 0;
  rep(i, N-2){
    chmax(ans, alt.at(i)+alt.at(i+1)+alt.at(i+2));
  }
  cout << ans << endl;
}