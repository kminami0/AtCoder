#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
#define EPSILON 1e-14
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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N), P(N), X(N);
    rep(i, N){
        cin >> A.at(i) >> P.at(i) >> X.at(i);
    }
    ll ans = INF;
    rep(i, N){
        if(X.at(i) > A.at(i)){
            chmin(ans, P.at(i));
        }
    }
    if(ans == INF){
        cout << -1 << '\n';
    }
    else{
        cout << ans << '\n';
    }
}