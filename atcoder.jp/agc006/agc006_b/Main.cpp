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
    ll N, x;
    cin >> N >> x;
    if(x == 1 || x == 2*N-1){
        cout << "No" << '\n';
        return 0;
    }
    vector<ll> ans(2*N-1, -1);
    ans.at(N-2) = x-1;
    ans.at(N-1) = x;
    ans.at(N) = x+1;
    ll p = 1;
    rep(i, 2*N-1){
        if(N-2 <= i && i <= N){
            continue;
        }
        if(x-1 <= p && p <= x+1){
            p = x+2;
        }
        ans.at(i) = p;
        p++;
    }
    cout << "Yes" << '\n';
    rep(i, 2*N-1){
        cout << ans.at(i) << '\n';
    }
}