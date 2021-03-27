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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll H, W, X, Y;
    cin >> H >> W >> X >> Y;
    X--;
    Y--;
    vector<string> S(H);
    rep(i, H){
        cin >> S.at(i);
    }
    ll ans = 1;
    rep2(i, 1, X+1){
        if(S.at(X-i).at(Y) == '.'){
            ans++;
        }
        else{
            break;
        }
    }
    rep2(i, X+1, H){
        if(S.at(i).at(Y) == '.'){
            ans++;
        }
        else{
            break;
        }
    }
    rep2(i, 1, Y+1){
        if(S.at(X).at(Y-i) == '.'){
            ans++;
        }
        else{
            break;
        }
    }
    rep2(i, Y+1, W){
        if(S.at(X).at(i) == '.'){
            ans++;
        }
        else{
            break;
        }
    }
    cout << ans << '\n';
}