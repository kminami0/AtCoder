#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
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
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    rep(i, H){
        rep(j, W){
            cin >> A.at(i).at(j);
        }
    }
    ll mini = INF;
    rep(i, H){
        rep(j, W){
            chmin(mini, A.at(i).at(j));
        }
    }
    ll ans = 0;
    rep(i, H){
        rep(j, W){
            ans += A.at(i).at(j) - mini;
        }
    }
    cout << ans << endl;
}