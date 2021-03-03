#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> B(H, vector<int>(W));
    rep(i, H){
        rep(j, W){
            cin >> A[i][j];
        }
    }
    rep(i, H){
        rep(j, W){
            cin >> B[i][j];
            B[i][j] = abs(B[i][j]-A[i][j]);
        }
    }
    vector<vector<vector<bool>>> dp(H, vector<vector<bool>>(W, vector<bool>(25441, false)));
    dp[0][0][B[0][0]+12720] = true;
    dp[0][0][-B[0][0]+12720] = true;
    rep(i, H){
        rep(j, W){
            if(i == 0 && j == 0){
                continue;
            }
            rep(k, 25441){
                if(k >= B[i][j] && k <= 25440-B[i][j]){
                    if(i == 0){
                        dp[i][j][k] = dp[i][j-1][k-B[i][j]] || dp[i][j-1][k+B[i][j]];
                    }
                    else if(j == 0){
                        dp[i][j][k] = dp[i-1][j][k-B[i][j]] || dp[i-1][j][k+B[i][j]];
                    }
                    else{
                        dp[i][j][k] = dp[i][j-1][k-B[i][j]] || dp[i][j-1][k+B[i][j]] || dp[i-1][j][k-B[i][j]] || dp[i-1][j][k+B[i][j]];
                    }
                }
                else if(k < B[i][j]){
                    if(i == 0){
                        dp[i][j][k] = dp[i][j-1][k+B[i][j]];
                    }
                    else if(j == 0){
                        dp[i][j][k] = dp[i-1][j][k+B[i][j]];
                    }
                    else{
                        dp[i][j][k] = dp[i][j-1][k+B[i][j]] || dp[i-1][j][k+B[i][j]];
                    }
                }
                else{
                    if(i == 0){
                        dp[i][j][k] = dp[i][j-1][k-B[i][j]];
                    }
                    else if(j == 0){
                        dp[i][j][k] = dp[i-1][j][k-B[i][j]];
                    }
                    else{
                        dp[i][j][k] = dp[i][j-1][k-B[i][j]] || dp[i-1][j][k-B[i][j]];
                    }
                }
            }
        }
    }
    int ans = 1e9;
    rep(i, 25441){
        if(dp[H-1][W-1][i]){
            chmin(ans, abs(i-12720));
        }
    }
    cout << ans << '\n';
}