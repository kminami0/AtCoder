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
    ll L;
    cin >> L;
    vector<vector<ll>> dp(201, vector<ll>(13, 0));
    //dp.at(i).at(j)は長さiの棒をj本に分割する方法の数
    dp.at(0).at(0) = 1;
    rep(i, 200){
        rep(j, 12){
            if(i+1 < j+1){
                break;
            }
            rep(k, i+1){
                dp.at(i+1).at(j+1) += dp.at(i-k).at(j);
            }
        }
    }
    cout << dp.at(L).at(12) << endl;
}