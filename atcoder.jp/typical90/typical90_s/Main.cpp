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
    ll N;
    cin >> N;
    vector<ll> A(2*N);
    rep(i, 2*N) cin >> A.at(i);
    vector<vector<ll>> dp(2*N+1, vector<ll>(2*N+1, INF));
    //dp.at(i).at(j)は[i, j)を取り除くのにかかる最小コスト
    rep(i, 2*N+1){
        dp.at(i).at(i) = 0;
    }
    rep(i, N){
        rep(j, 2*N-2*(i+1)+1){
            dp.at(j).at(j+2*(i+1)) = dp.at(j+1).at(j+2*(i+1)-1) + abs(A.at(j)-A.at(j+2*(i+1)-1));
            rep2(k, j+1, j+2*(i+1)){
                chmin(dp.at(j).at(j+2*(i+1)), dp.at(j).at(k)+dp.at(k).at(j+2*(i+1)));
            }
        }
    }
    cout << dp.at(0).at(2*N) << '\n';
}