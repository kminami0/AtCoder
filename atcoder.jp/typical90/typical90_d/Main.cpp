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
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    rep(i, H){
        rep(j, W){
            cin >> A.at(i).at(j);
        }
    }
    vector<ll> R(H, 0);
    vector<ll> C(W, 0);
    rep(i, H){
        rep(j, W){
            R.at(i) += A.at(i).at(j);
        }
    }
    rep(j, W){
        rep(i, H){
            C.at(j) += A.at(i).at(j);
        }
    }
    rep(i, H){
        rep(j, W-1){
            cout << R.at(i) + C.at(j) - A.at(i).at(j) << " ";
        }
        cout << R.at(i) + C.at(W-1) - A.at(i).at(W-1) << '\n';
    }
}