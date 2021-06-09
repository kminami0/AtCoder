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
    ll Q;
    cin >> Q;
    deque<ll> d;
    rep(i, Q){
        ll t, x;
        cin >> t >> x;
        if(t == 1){
            d.push_front(x);
        }
        else if(t == 2){
            d.push_back(x);
        }
        else{
            cout << d.at(x-1) << '\n';
        }
    }
}