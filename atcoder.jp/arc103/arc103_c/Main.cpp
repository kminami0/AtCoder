#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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
    string s;
    cin >> s;
    ll n = sz(s);
    if(s.at(0) == '0' || s.at(n-1) == '1'){
        cout << -1 << '\n';
        return 0;
    }
    rep(i, n-1){
        if(s.at(i) != s.at(n-2-i)){
            cout << -1 << '\n';
            return 0;
        }
    }
    s.at(n-1) = '1';
    vector<pair<ll, ll>> edges(0);
    ll p = n-1;
    rep(i, n-1){
        edges.push_back({n-1-i, p+1});
        if(s.at(n-2-i) == '1'){
            p = n-2-i;
        }
    }
    rep(i, n-1){
        cout << edges.at(i).first << ' ' << edges.at(i).second << '\n';
    }
}