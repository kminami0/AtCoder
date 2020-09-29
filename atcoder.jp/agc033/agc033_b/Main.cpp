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
    ll H, W, N, sr, sc;
    cin >> H >> W >> N >> sr >> sc;
    string S, T;
    cin >> S >> T;
    vector<pair<pair<ll, ll>, pair<ll, ll>>> dp(2*N);
    dp.at(0) = {{1, 1}, {H, W}};
    rep(i, 2*N-1){
      if(i % 2 == 0){
        if(S.at(N-1-i/2) == 'L'){
          dp.at(i+1) = {{dp.at(i).first.first, dp.at(i).first.second+1}, {dp.at(i).second.first, dp.at(i).second.second}};
        }
        if(S.at(N-1-i/2) == 'R'){
          dp.at(i+1) = {{dp.at(i).first.first, dp.at(i).first.second}, {dp.at(i).second.first, dp.at(i).second.second-1}};
        }
        if(S.at(N-1-i/2) == 'U'){
          dp.at(i+1) = {{dp.at(i).first.first+1, dp.at(i).first.second}, {dp.at(i).second.first, dp.at(i).second.second}};
        }
        if(S.at(N-1-i/2) == 'D'){
          dp.at(i+1) = {{dp.at(i).first.first, dp.at(i).first.second}, {dp.at(i).second.first-1, dp.at(i).second.second}};
        }
        if(dp.at(i+1).first.first > dp.at(i+1).second.first || dp.at(i+1).first.second > dp.at(i+1).second.second){
          cout << "NO" << endl;
          return 0;
        }
      }
      else{
        if(T.at(N-2-i/2) == 'L'){
          dp.at(i+1) = {{dp.at(i).first.first, dp.at(i).first.second}, {dp.at(i).second.first, dp.at(i).second.second+1}};
        }
        if(T.at(N-2-i/2) == 'R'){
          dp.at(i+1) = {{dp.at(i).first.first, dp.at(i).first.second-1}, {dp.at(i).second.first, dp.at(i).second.second}};
        }
        if(T.at(N-2-i/2) == 'U'){
          dp.at(i+1) = {{dp.at(i).first.first, dp.at(i).first.second}, {dp.at(i).second.first+1, dp.at(i).second.second}};
        }
        if(T.at(N-2-i/2) == 'D'){
          dp.at(i+1) = {{dp.at(i).first.first-1, dp.at(i).first.second}, {dp.at(i).second.first, dp.at(i).second.second}};
        }
        if(dp.at(i+1).first.first == 0){
          dp.at(i+1).first.first = 1;
        }
        if(dp.at(i+1).first.second == 0){
          dp.at(i+1).first.second = 1;
        }
        if(dp.at(i+1).second.first == H+1){
          dp.at(i+1).second.first = H;
        }
        if(dp.at(i+1).second.second == W+1){
          dp.at(i+1).second.second = W;
        }
      }
    }
    if(dp.at(2*N-1).first.first <= sr && sr <= dp.at(2*N-1).second.first){
      if(dp.at(2*N-1).first.second <= sc && sc <= dp.at(2*N-1).second.second){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    }
    else{
      cout << "NO" << endl;
    }
}