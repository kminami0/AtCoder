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
    ll N;
    cin >> N;
    vector<ll> x(N), y(N);
    rep(i, N){
        cin >> x.at(i) >> y.at(i);
        x.at(i) *= 2;
        y.at(i) *= 2;
    }
    sort(all(x));
    sort(all(y));
    ll xm = (x.at(N/2) + x.at((N-1)/2)) / 2;
    ll ym = (y.at(N/2) + y.at((N-1)/2)) / 2;
    ll ans = 0;
    rep(i, N){
        ans += abs(xm-x.at(i));
        ans += abs(ym-y.at(i));
    }
    ans /= 2;
    cout << ans << '\n';
}