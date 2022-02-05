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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> pizza(0);
    pizza.push_back(0);
    ll deg = 0;
    rep(i, N){
        deg += A.at(i);
        deg %= 360;
        pizza.push_back(deg);
    }
    sort(all(pizza));
    pizza.push_back(360);
    ll ans = 0;
    rep(i, sz(pizza)-1){
        chmax(ans, pizza.at(i+1)-pizza.at(i));
    }
    cout << ans << '\n';
}