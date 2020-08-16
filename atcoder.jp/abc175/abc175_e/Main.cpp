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

vector<vector<vector<ll>>> dp(3000, vector<vector<ll>>(3000, vector<ll>(4, -1*INF)));

int main()
{
    ll R, C, K;
    cin >> R >> C >> K;
    vector<ll> r(K), c(K), v(K);
    map<pair<ll, ll>, ll> item;
    rep(i, K){
        cin >> r.at(i) >> c.at(i) >> v.at(i);
        r.at(i)--;
        c.at(i)--;
        item[{r.at(i), c.at(i)}] = v.at(i);
    }
    rep(i, R){
      rep(j, C){
        rep(k, 4){
          if(item.count({i, j})){
            if(i == 0){
              if(j == 0){
                dp.at(0).at(0).at(0) = 0;
                dp.at(0).at(0).at(1) = item.at({0, 0});
              }
              else{
                if(k == 0){
                  dp.at(0).at(j).at(0) = dp.at(0).at(j-1).at(0);
                }
                else{
                  dp.at(0).at(j).at(k) = max(dp.at(0).at(j-1).at(k), dp.at(0).at(j-1).at(k-1)+item.at({0, j}));
                }
              }
            }
            else{
              if(j == 0){
                if(k == 0){
                  dp.at(i).at(0).at(0) = max(dp.at(i-1).at(0).at(0), dp.at(i-1).at(0).at(1));
                }
                else if(k == 1){
                  dp.at(i).at(0).at(1) = dp.at(i).at(0).at(0) + item.at({i, 0});
                }
                else{
                  continue;
                }
              }
              else{
                if(k == 0){
                  dp.at(i).at(j).at(0) = max(dp.at(i-1).at(j).at(0), dp.at(i-1).at(j).at(1));
                  chmax(dp.at(i).at(j).at(0), dp.at(i-1).at(j).at(2));
                  chmax(dp.at(i).at(j).at(0), dp.at(i-1).at(j).at(3));
                  chmax(dp.at(i).at(j).at(0), dp.at(i).at(j-1).at(0));
                }
                else if(k == 1){
                  dp.at(i).at(j).at(1) = max(dp.at(i).at(j-1).at(1), dp.at(i-1).at(j).at(0)+item.at({i, j}));
                  chmax(dp.at(i).at(j).at(1), dp.at(i-1).at(j).at(1)+item.at({i, j}));
                  chmax(dp.at(i).at(j).at(1), dp.at(i-1).at(j).at(2)+item.at({i, j}));
                  chmax(dp.at(i).at(j).at(1), dp.at(i-1).at(j).at(3)+item.at({i, j}));
                  chmax(dp.at(i).at(j).at(1), dp.at(i).at(j-1).at(0)+item.at({i, j}));
                }
                else{
                  dp.at(i).at(j).at(k) = max(dp.at(i).at(j-1).at(k), dp.at(i).at(j-1).at(k-1)+item.at({i, j}));
                }
              }
            }
          }
          else{
            if(i == 0){
              if(j == 0){
                dp.at(0).at(0).at(0) = 0;
              }
              else{
                dp.at(0).at(j).at(k) = dp.at(0).at(j-1).at(k);
              }
            }
            else{
              if(j == 0){
                dp.at(i).at(0).at(0) = max(dp.at(i-1).at(0).at(0), dp.at(i-1).at(0).at(1));
              }
              else{
                if(k == 0){
                  dp.at(i).at(j).at(0) = max(dp.at(i-1).at(j).at(0), dp.at(i-1).at(j).at(1));
                  chmax(dp.at(i).at(j).at(0), dp.at(i-1).at(j).at(2));
                  chmax(dp.at(i).at(j).at(0), dp.at(i-1).at(j).at(3));
                  chmax(dp.at(i).at(j).at(0), dp.at(i).at(j-1).at(0));
                }
                else{
                  dp.at(i).at(j).at(k) = dp.at(i).at(j-1).at(k);
                }
              }
            }
          }
//          cout << i << " " << j << " " << k << " " << dp.at(i).at(j).at(k) << endl;
        }
      }
    }
    ll ans = max(dp.at(R-1).at(C-1).at(0), dp.at(R-1).at(C-1).at(1));
    chmax(ans, dp.at(R-1).at(C-1).at(2));
    chmax(ans, dp.at(R-1).at(C-1).at(3));
    cout << ans << endl;
}