#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int main()
{
  ll N, M, K;
  cin >> N >> M >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A.at(i);
  vector<ll> B(M);
  rep(i, M) cin >> B.at(i);
  vector<ll> SA(N+2, 0);
  vector<ll> SB(M+2, 0);
  rep(i, N){
    SA.at(i+1) = SA.at(i) + A.at(i);
  }
  rep(i, M){
    SB.at(i+1) = SB.at(i) + B.at(i);
  }
  SA.at(N+1) = INF;
  SB.at(M+1) = INF;
  ll ans = 0;
  rep(i, N+1){
    if(SA.at(i) > K){
      break;
    }
    ll res = K - SA.at(i);
    ll l = 0;
    ll r = M+1;
    // SB.at(l) <= res < SB.at(r)
    while(r-l > 1){
      ll c = (l+r)/2;
      if(SB.at(c) <= res){
        l = c;
      }
      else{
        r = c;
      }
    }
    chmax(ans, i+l);
  }
  cout << ans << endl;
}