#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000 //10^9
#define EPSILON 0.00000000000001 // 10^-14
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
    int X, Y, N;
    cin >> X >> Y >> N;
    vector<int> t(N), h(N);
    rep(i, N){
        cin >> t.at(i) >> h.at(i);
    }
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(X+Y+1, vector<int>(X+1, -INF)));
    //dp.at(i).at(j).at(k)はi番目までのトッピングのうちk種類のトッピングを使用してj枚のチケットを消費して得られる最大の嬉しさ
    rep(i, N+1){
        dp.at(i).at(0).at(0) = 0;
    }
    int ans = 0;
    rep(i, N){
        rep(j, X+Y+1){
            rep(k, min(X, i+1)){
                if(j >= t.at(i)){
                    dp.at(i+1).at(j).at(k+1) = max(dp.at(i).at(j-t.at(i)).at(k) + h.at(i), dp.at(i).at(j).at(k+1));
                }
                else{
                    dp.at(i+1).at(j).at(k+1) = dp.at(i).at(j).at(k+1);
                }
                chmax(ans, dp.at(i+1).at(j).at(k+1));
                // cout << i+1 << " " << j << " " << k+1 << " " << dp.at(i+1).at(j).at(k+1) << endl;
            }
        }
    }
    cout << ans << '\n';
}