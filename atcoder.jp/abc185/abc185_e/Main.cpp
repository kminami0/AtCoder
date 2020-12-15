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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> B(M);
    rep(i, M) cin >> B.at(i);
    A.push_back(-1);
    B.push_back(-1);
    vector<vector<ll>> dp(N+1, vector<ll>(M+1, 0));
    rep(i, N+1){
      rep(j, M+1){
        if(i == 0 && j == 0){
          continue;
        }
        else if(i == 0){
          dp.at(i).at(j) = dp.at(i).at(j-1) + 1;
        }
        else if(j == 0){
          dp.at(i).at(j) = dp.at(i-1).at(j) + 1;
        }
        else{
          if(A.at(i-1) == B.at(j-1)){
            dp.at(i).at(j) = min(dp.at(i-1).at(j-1), min(dp.at(i).at(j-1)+1, dp.at(i-1).at(j)+1));
          }
          else{
            dp.at(i).at(j) = min(dp.at(i-1).at(j-1)+1, min(dp.at(i).at(j-1)+1, dp.at(i-1).at(j)+1));
          }
        }
      }
    }
    cout << dp.at(N).at(M) << endl;
}