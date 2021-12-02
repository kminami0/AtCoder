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
    ll N, W;
    cin >> N >> W;
    vector<pair<ll, ll>> cheese(N);
    rep(i, N){
        cin >> cheese.at(i).first >> cheese.at(i).second;
    }
    sort(all(cheese));
    reverse(all(cheese));
    ll ans = 0;
    ll weight = 0;
    rep(i, N){
        ans += cheese.at(i).first * min(W-weight, cheese.at(i).second);
        weight += min(W-weight, cheese.at(i).second);
    }
    cout << ans << '\n';
}