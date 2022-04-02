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
    map<ll, ll> xcnt, ycnt;
    rep(i, 3){
        ll x, y;
        cin >> x >> y;
        xcnt[x]++;
        ycnt[y]++;
    }
    ll x, y;
    for(auto p : xcnt){
        if(p.second == 1){
            x = p.first;
            break;
        }
    }
    for(auto p : ycnt){
        if(p.second == 1){
            y = p.first;
            break;
        }
    }
    cout << x << " " << y << endl;
}