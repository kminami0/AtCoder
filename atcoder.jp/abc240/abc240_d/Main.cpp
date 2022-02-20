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
    vector<ll> a(N);
    rep(i, N) cin >> a.at(i);
    stack<pair<ll, ll>> S;
    rep(i, N){
        pair<ll, ll> p = {-1, -1};
        if(!S.empty()){
            p = S.top();
        }
        if(p.first == a.at(i)){
            if(p.second == a.at(i) - 1){
                rep(j, a.at(i) - 1){
                    S.pop();
                }
            }
            else{
                S.push({a.at(i), p.second + 1});
            }
        }
        else{
            S.push({a.at(i), 1});
        }
        cout << sz(S) << '\n';
    }
}