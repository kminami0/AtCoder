#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18
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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    ll ans = 2e18;
    rep(i, N){
        vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(N+1, vector<ll>(i+1, -INF)));
        //dp.at(j).at(k).at(l)はj番目までのうちk個使ってi+1で割った余りがlになる素材の魔力合計の最大値
        rep(j, N+1){
            rep(k, N+1){
                rep(l, i+1){
                    dp.at(j).at(k).at(l) = -INF;
                }
            }
        }
        rep(j, N+1){
            dp.at(j).at(0).at(0) = 0;
        }
        rep(j, N){
            rep(k, i+2){
                rep(l, i+1){
                    chmax(dp.at(j+1).at(k).at(l), dp.at(j).at(k).at(l));
                    if(k < i+1){
                        chmax(dp.at(j+1).at(k+1).at((l+A.at(j))%(i+1)), dp.at(j).at(k).at(l)+A.at(j));
                    }
                }
            }
        }
        if(dp.at(N).at(i+1).at(X%(i+1)) >= 0){
            chmin(ans, (X - dp.at(N).at(i+1).at(X%(i+1))) / (i+1));   
        }
    }
    cout << ans << '\n';
}