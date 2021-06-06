#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
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
    int N;
    cin >> N;
    vector<int> T(N);
    rep(i, N) cin >> T.at(i);
    vector<vector<bool>> dp(N+1, vector<bool>(100001, false));
    dp.at(0).at(0) = true;
    rep(i, N){
        rep(j, 100001){
            if(j >= T.at(i)){
                dp.at(i+1).at(j) = dp.at(i).at(j-T.at(i)) || dp.at(i).at(j);
            }
            else{
                dp.at(i+1).at(j) = dp.at(i).at(j);
            }
        }
    }
    ll sum = 0;
    rep(i, N){
        sum += T.at(i);
    }
    ll time = sum / 2;
    while(true){
        if(dp.at(N).at(time)){
            cout << max(time, sum-time) << '\n';
            return 0;
        }
        else{
            time++;
        }
    }
}