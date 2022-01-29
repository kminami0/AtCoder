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
    ll N, L, W;
    cin >> N >> L >> W;
    vector<ll> a(N+1);
    rep(i, N) cin >> a.at(i);
    a.at(N) = L;
    ll ans = 0;
    ll p = 0;
    rep(i, N+1){
        if(a.at(i) <= p){
            chmax(p, a.at(i)+W);
            continue;
        }
        ll maisu = (a.at(i) - p + W - 1) / W;
        ans += maisu;
        p += maisu * W;
        chmax(p, a.at(i)+W);
    }
    cout << ans << '\n';
}