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
    ll N, X;
    cin >> N >> X;
    vector<ll> a(N), b(N);
    rep(i, N){
        cin >> a.at(i) >> b.at(i);
    }
    vector<vector<bool>> dp(N+1, vector<bool>(10001, false));
    dp.at(0).at(0) = true;
    rep(i, N){
        rep(j, 10001){
            if(j < a.at(i)){
                dp.at(i+1).at(j) = false;
            }
            else if(j < b.at(i)){
                dp.at(i+1).at(j) = dp.at(i).at(j-a.at(i));
            }
            else{
                dp.at(i+1).at(j) = dp.at(i).at(j-a.at(i)) || dp.at(i).at(j-b.at(i));
            }
        }
    }
    if(dp.at(N).at(X)){
        cout << "Yes" << '\n';
    }
    else{
        cout << "No" << '\n';
    }
}