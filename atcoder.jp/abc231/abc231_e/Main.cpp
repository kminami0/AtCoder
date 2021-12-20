#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
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
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    A.push_back(INF);
    vector<vector<ll>> dp(N+1, vector<ll>(2, INF));
    dp.at(0).at(0) = 0;
    vector<ll> x(N);
    rep(i, N){
        x.at(N-1-i) = X / A.at(N-1-i);
        X %= A.at(N-1-i);
    }
    rep(i, N){
        rep(j, 2){
            rep(k, 2){
                chmin(dp.at(i+1).at(j), dp.at(i).at(k) + abs(x.at(i) + k - j * A.at(i+1) / A.at(i)));
            }
        }
    }
    cout << dp.at(N).at(0) << '\n';
}