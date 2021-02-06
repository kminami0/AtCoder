#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H){
        cin >> S.at(i);
    }
    ll ans = 0;
    bool flag = false;
    rep(i, H-1){
        rep(j, W){
            if(S.at(i).at(j) != S.at(i+1).at(j)){
                if(!flag){
                    ans++;
                    flag = true;
                }
            }
            else{
                flag = false;
            }
        }
    }
    flag = false;
    rep(i, W-1){
        rep(j, H){
            if(S.at(j).at(i) != S.at(j).at(i+1)){
                if(!flag){
                    ans++;
                    flag = true;
                }
            }
            else{
                flag = false;
            }
        }
    }
    cout << ans << '\n';
}