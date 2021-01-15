#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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
    ll N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    vector<ll> a(N), b(N), c(N);
    rep(i, N){
        cin >> a.at(i) >> b.at(i) >> c.at(i);
    }
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(401, vector<ll>(401, INF)));
    dp.at(0).at(0).at(0) = 0;
    rep(i, N){
        rep(j, 401){
            rep(k, 401){
                if(j >= a.at(i) && k >= b.at(i)){
                    dp.at(i+1).at(j).at(k) = min(dp.at(i).at(j-a.at(i)).at(k-b.at(i)) + c.at(i), dp.at(i).at(j).at(k));
                }
                else{
                    dp.at(i+1).at(j).at(k) = dp.at(i).at(j).at(k);
                }
            }
        }
    }
    ll ans = INF;
    rep(i, 400){
        rep(j, 400){
            if((i+1)*Mb == (j+1)*Ma){
                chmin(ans, dp.at(N).at(i+1).at(j+1));
            }
        }
    }
    if(ans < INF){
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }
}