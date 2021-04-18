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
    ll R, C, D;
    cin >> R >> C >> D;
    vector<vector<ll>> A(R, vector<ll>(C));
    rep(i, R){
        rep(j, C){
            cin >> A.at(i).at(j);
        }
    }
    ll ans = 0;
    rep(i, R){
        rep(j, C){
            if(D % 2 == (i+j) % 2 && i+j <= D){
                chmax(ans, A.at(i).at(j));
            }
        }
    }
    cout << ans << '\n';
}
