#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll H, W, K;
    cin >> H >> W >> K;
    vector<vector<char>> grid(H, vector<char>(W, '.'));
    rep(i, K){
        ll h, w;
        cin >> h >> w;
        h--;
        w--;
        cin >> grid[h][w];
    }
    vector<vector<mint>> dp(H, vector<mint>(W, 0));
    dp[H-1][W-1] = mint(3).pow(H*W-K);
    for(int i = H-1; i>=0; i--){
        for(int j = W-1; j>=0; j--){
            if(grid[i][j] == 'R'){
                if(j != W-1){
                    dp[i][j] = dp[i][j+1];
                }
            }
            else if(grid[i][j] == 'D'){
                if(i != H-1){
                    dp[i][j] = dp[i+1][j];
                }
            }
            else if(grid[i][j] == 'X'){
                if(i != H-1){
                    if(j != W-1){
                        dp[i][j] = dp[i+1][j] + dp[i][j+1];
                    }
                    else{
                        dp[i][j] = dp[i+1][j];
                    }
                }
                else{
                    if(j != W-1){
                        dp[i][j] = dp[i][j+1];
                    }
                }
            }
            else{
                if(i != H-1){
                    if(j != W-1){
                        dp[i][j] = (dp[i][j+1] + dp[i+1][j]) * 2 / 3;
                    }
                    else{
                        dp[i][j] = dp[i+1][j] * 2 / 3;
                    }
                }
                else{
                    if(j != W-1){
                        dp[i][j] = dp[i][j+1] * 2 / 3;
                    }
                }
            }
        }
    }
    cout << dp[0][0].val() << '\n';
}