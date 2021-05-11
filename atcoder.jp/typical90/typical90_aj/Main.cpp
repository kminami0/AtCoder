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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> X(N), Y(N);
    ll minX = INF;
    ll minY = INF;
    ll maxX = -INF;
    ll maxY = -INF;
    rep(i, N){
        ll x, y;
        cin >> x >> y;
        X.at(i) = x - y;
        Y.at(i) = x + y;
        chmax(maxX, X.at(i));
        chmax(maxY, Y.at(i));
        chmin(minX, X.at(i));
        chmin(minY, Y.at(i));
    }
    rep(i, Q){
        ll q;
        cin >> q;
        q--;
        ll ans = max(maxX-X.at(q), X.at(q)-minX);
        chmax(ans, max(maxY-Y.at(q), Y.at(q)-minY));
        cout << ans << '\n';
    }
}