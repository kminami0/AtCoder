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
    ll N, W;
    cin >> N >> W;
    vector<ll> w(N), v(N), d(N);
    ll value_sum = 0;
    ll weight_sum = 0;
    ll diff_sum = 0;
    rep(i, N){
        cin >> w.at(i) >> v.at(i);
        d.at(i) = w.at(i) - w.at(0);
        value_sum += v.at(i);
        weight_sum += w.at(i);
        diff_sum += d.at(i);
    }
    if(W >= weight_sum){
        cout << value_sum << endl;
        return 0;
    }
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(N+1, vector<ll>(diff_sum+1, 0)));
    // dp.at(i).at(j).at(k)は始めのi個からj個選んで重さの和がj*w_1+k以下のときの価値の最大値
    rep(i, N){
        rep2(j, 1, i+2){
            rep(k, diff_sum+1){
                if(k >= d.at(i)){
                    dp.at(i+1).at(j).at(k) = max(dp.at(i).at(j-1).at(k-d.at(i)) + v.at(i), dp.at(i).at(j).at(k));
                }
                else{
                    dp.at(i+1).at(j).at(k) = dp.at(i).at(j).at(k);
                }
            }
        }
    }
    ll ans = 0;

    rep(i, N+1){
        rep(j, diff_sum+1){
            if(i*w.at(0)+j > W){
                break;
            }
            chmax(ans, dp.at(N).at(i).at(j));
        }
    }
    cout << ans << endl;
}