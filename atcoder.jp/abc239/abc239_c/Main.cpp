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
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    set<pair<ll, ll>> S, T;
    S.insert({x1+1, y1+2});
    S.insert({x1+1, y1-2});
    S.insert({x1-1, y1+2});
    S.insert({x1-1, y1-2});
    S.insert({x1+2, y1+1});
    S.insert({x1+2, y1-1});
    S.insert({x1-2, y1+1});
    S.insert({x1-2, y1-1});
    T.insert({x2+1, y2+2});
    T.insert({x2+1, y2-2});
    T.insert({x2-1, y2+2});
    T.insert({x2-1, y2-2});
    T.insert({x2+2, y2+1});
    T.insert({x2+2, y2-1});
    T.insert({x2-2, y2+1});
    T.insert({x2-2, y2-1});
    for(auto p : S){
        if(T.count(p)){
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
}