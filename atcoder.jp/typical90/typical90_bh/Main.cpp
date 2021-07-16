#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
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
int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> dp(N, INF);
    vector<ll> lis(N, 0);
    rep(i, N){
        auto iter = lower_bound(all(dp), A.at(i));
        *iter = A.at(i);
        auto iter2 = lower_bound(all(dp), INF);
        ll len = iter2 - begin(dp);
        lis.at(i) = len;
    }
    vector<ll> dp2(N, INF);
    vector<ll> lis2(N, 0);
    rep(i, N){
        auto iter = lower_bound(all(dp2), A.at(N-1-i));
        *iter = A.at(N-1-i);
        auto iter2 = lower_bound(all(dp2), INF);
        ll len = iter2 - begin(dp2);
        lis2.at(i) = len;
    }
    ll ans = 0;
    rep(i, N){
        chmax(ans, lis.at(i)+lis2.at(N-1-i)-1);
    }
    cout << ans << '\n';
}