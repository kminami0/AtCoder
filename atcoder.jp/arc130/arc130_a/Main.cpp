#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
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
    ll N;
    string S;
    cin >> N >> S;
    ll cnt = 1;
    ll ans = 0;
    rep(i, N-1){
        if(S.at(i) != S.at(i+1)){
            ans += cnt * (cnt-1) / 2;
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    ans += cnt * (cnt-1) / 2;
    cout << ans << '\n';
}