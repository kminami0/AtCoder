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
    vector<tuple<ll, ll, ll>> job(N);
    rep(i, N){
        ll D, C, S;
        cin >> D >> C >> S;
        job.at(i) = {D, C, S};
    }
    sort(all(job));
    vector<vector<ll>> dp(N+1, vector<ll>(5001, 0));
    rep(i, N){
        rep(j, 5001){
            if(j < get<1>(job.at(i)) || j > get<0>(job.at(i))){
                dp.at(i+1).at(j) = dp.at(i).at(j);
            }
            else{
                dp.at(i+1).at(j) = max(dp.at(i).at(j), dp.at(i).at(j-get<1>(job.at(i))) + get<2>(job.at(i)));
            }
        }
    }
    ll ans = 0;
    rep(i, 5001){
        chmax(ans, dp.at(N).at(i));
    }
    cout << ans << '\n';
}