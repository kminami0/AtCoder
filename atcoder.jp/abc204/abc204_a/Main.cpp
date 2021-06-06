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
    ll x, y;
    cin >> x >> y;
    set<ll> hand;
    hand.insert(x);
    hand.insert(y);
    if(x == y){
        cout << x << '\n';
    }
    else if(!hand.count(0)){
        cout << 0 << '\n';
    }
    else if(!hand.count(1)){
        cout << 1 << '\n';
    }
    else if(!hand.count(2)){
        cout << 2 << '\n';
    }
}