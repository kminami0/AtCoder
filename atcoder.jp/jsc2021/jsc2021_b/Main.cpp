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
    ll N, M;
    cin >> N >> M;
    set<ll> A, B;
    rep(i, N){
        ll a;
        cin >> a;
        A.insert(a);
    }
    rep(i, M){
        ll a;
        cin >> a;
        B.insert(a);
    }
    vector<ll> ans(0);
    for(ll x : A){
        if(!B.count(x)){
            ans.push_back(x);
        }
    }
    for(ll x : B){
        if(!A.count(x)){
            ans.push_back(x);
        }
    }
    if(sz(ans) == 0){
        return 0;
    }
    sort(all(ans));
    rep(i, sz(ans)-1){
        cout << ans.at(i) << " ";
    }
    cout << ans.at(sz(ans)-1) << endl;
}