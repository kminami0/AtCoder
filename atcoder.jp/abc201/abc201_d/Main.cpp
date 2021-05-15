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
    ll H, W;
    cin >> H >> W;
    vector<string> A(H);
    rep(i, H){
        cin >> A.at(i);
    }
    vector<vector<ll>> dp(H, vector<ll>(W, 0));
    //dp.at(i).at(j)はマス(i, j)からゲームを開始したときの、先攻の点数-後攻の点数
    rep(i, H){
        rep(j, W){
            if(i == 0 && j == 0){
                continue;
            }
            if(i == 0){
                if(A.at(H-1).at(W-j) == '+'){
                    dp.at(H-1-i).at(W-1-j) = 1 - dp.at(H-1-i).at(W-j);
                }
                else{
                    dp.at(H-1-i).at(W-1-j) = -1 - dp.at(H-1-i).at(W-j);
                }
            }
            else if(j == 0){
                if(A.at(H-i).at(W-1) == '+'){
                    dp.at(H-1-i).at(W-1-j) = 1 - dp.at(H-i).at(W-1-j);
                }
                else{
                    dp.at(H-1-i).at(W-1-j) = -1 - dp.at(H-i).at(W-1-j);
                }
            }
            else{
                if(A.at(H-1-i).at(W-j) == '+'){
                    dp.at(H-1-i).at(W-1-j) = 1 - dp.at(H-1-i).at(W-j);
                }
                else{
                    dp.at(H-1-i).at(W-1-j) = -1 - dp.at(H-1-i).at(W-j);
                }
                if(A.at(H-i).at(W-1-j) == '+'){
                    chmax(dp.at(H-1-i).at(W-1-j), 1 - dp.at(H-i).at(W-1-j));
                }
                else{
                    chmax(dp.at(H-1-i).at(W-1-j), -1 - dp.at(H-i).at(W-1-j));
                }
            }
        }
    }
    if(dp.at(0).at(0) > 0){
        cout << "Takahashi" << '\n';
    }
    else if(dp.at(0).at(0) < 0){
        cout << "Aoki" << '\n';
    }
    else{
        cout << "Draw" << '\n';
    }
}