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
    vector<ll> X(N), C(N);
    vector<vector<ll>> ball(N+2, vector<ll>(0));
    ball.at(0).emplace_back(0);
    rep(i, N){
        cin >> X.at(i) >> C.at(i);
        ball.at(C.at(i)).emplace_back(X.at(i));
    }
    ball.at(N+1).emplace_back(0);
    rep(i, N+2){
        sort(all(ball.at(i)));
    }
    vector<vector<ll>> dp(N+2, vector<ll>(2, 0));
    //dp.at(i).at(0)は色iまでを回収して左端にいるときの最小時間
    //dp.at(i).at(1)は右端にいる
    ll p = 0;
    rep(i, N+1){
        if(ball.at(i+1).empty()){
            dp.at(i+1).at(0) = dp.at(i).at(0);
            dp.at(i+1).at(1) = dp.at(i).at(1);
        }
        else{
            ll preleft = ball.at(p).at(0);
            ll preright = ball.at(p).at(sz(ball.at(p))-1);
            ll left = ball.at(i+1).at(0);
            ll right = ball.at(i+1).at(sz(ball.at(i+1))-1);
            // preleft -> left
            dp.at(i+1).at(0) = abs(preleft-right) + right - left + dp.at(i).at(0);
            // preleft -> right
            dp.at(i+1).at(1) = abs(preleft-left) + right - left + dp.at(i).at(0);
            // preright -> left
            chmin(dp.at(i+1).at(0), abs(preright-right) + right - left + dp.at(i).at(1));
            // preright -> right
            chmin(dp.at(i+1).at(1), abs(preright-left) + right - left + dp.at(i).at(1));
            p = i+1;
        }
    }
    cout << min(dp.at(N+1).at(0), dp.at(N+1).at(1)) << '\n';
}