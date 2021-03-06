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
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> acc(N+1, 0);
    rep(i, N){
        acc.at(i+1) = acc.at(i) + A.at(i);
    }
    ll ans = 0;
    rep(i, N){
        ans += A.at(i)*A.at(i);
    }
    ans *= N-1;
    rep(i, N-1){
        ans -= 2 * A.at(i) * (acc.at(N)-acc.at(i+1));
    }
    cout << ans << '\n';
}