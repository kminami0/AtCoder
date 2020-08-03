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

ll cutting(vector<ll> A, ll K){
  if(K == 0){
    return INF;
  }
  ll c = 0;
  rep(i, sz(A)){
    if(A.at(i) % K == 0){
      c += A.at(i) / K - 1;
    }
    else{
      c += A.at(i) / K;
    }
  }
  return c;
}

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    ll l = 0;
    ll r = 1000000000;
    while(r-l > 1){
      ll c = (l+r) / 2;
      if(cutting(A, c) <= K){
        r = c;
      }
      else{
        l = c;
      }
    }
    cout << r << endl;
}