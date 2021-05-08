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
    vector<ll> a(N);
    vector<ll> rem(200, 0);
    rep(i, N){
        cin >> a.at(i);
        a.at(i) %= 200;
        rem.at(a.at(i))++;
    } 
    ll ans = 0;
    rep(i, 200){
        ans += rem.at(i) * (rem.at(i) - 1) / 2;
    }
    cout << ans << '\n';
}