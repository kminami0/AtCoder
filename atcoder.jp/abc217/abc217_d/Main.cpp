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
    ll L, Q;
    cin >> L >> Q;
    set<ll> cut;
    cut.insert(0);
    cut.insert(L);
    rep(i, Q){
        ll c, x;
        cin >> c >> x;
        if(c == 1){
            cut.insert(x);
        }
        else{
            auto iter = cut.lower_bound(x);
            ll right = *iter;
            iter--;
            ll left = *iter;
            cout << right-left << '\n';
        }
    }
}