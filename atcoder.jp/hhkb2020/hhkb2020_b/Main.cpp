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
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H){
        cin >> S.at(i);
    }
    ll ans = 0;
    rep(i, H){
        rep(j, W-1){
            if(S.at(i).at(j) == '.' && S.at(i).at(j+1) == '.'){
                ans++;
            }
        }
    }
    rep(i, H-1){
        rep(j, W){
            if(S.at(i).at(j) == '.' && S.at(i+1).at(j) == '.'){
                ans++;
            }
        }
    }
    cout << ans << endl;
}