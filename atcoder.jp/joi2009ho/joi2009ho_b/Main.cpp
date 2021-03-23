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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll d, n, m;
    cin >> d >> n >> m;
    vector<ll> dist(n, 0);
    rep(i, n-1){
        cin >> dist.at(i+1);
    }
    dist.emplace_back(d);
    sort(all(dist));
    vector<ll> k(m);
    rep(i, m){
        cin >> k.at(i);
    }
    ll ans = 0;
    rep(i, m){
        auto it = lower_bound(all(dist), k.at(i));
        if(it != begin(dist)){
            ans += min(*it - k.at(i), k.at(i) - *(it-1));
        }
    }
    cout << ans << '\n';
}