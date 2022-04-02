#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
#define INF 1e18+999999
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
    ll N, K, X;
    cin >> N >> K >> X;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    ll ans = 0;
    rep(i, N){
        ll c = A.at(i) / X;
        if(K >= c){
            K -= c;
            A.at(i) -= c*X;
        }
        else{
            A.at(i) -= K*X;
            K = 0;
            break;
        }
    }
    sort(all(A));
    reverse(all(A));
    rep(i, N){
        if(K == 0){
            break;
        }
        A.at(i) = 0;
        K--;
    }
    rep(i, N){
        ans += A.at(i);
    }
    cout << ans << '\n';
}