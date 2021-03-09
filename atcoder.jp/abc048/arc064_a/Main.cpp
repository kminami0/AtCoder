#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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
    ll N, x;
    cin >> N >> x;
    vector<ll> a(N);
    rep(i, N) cin >> a.at(i);
    ll ans = 0;
    rep(i, N-1){
        if(a.at(i)+a.at(i+1) > x){
            ll num = a.at(i)+a.at(i+1)-x;
            ans += num;
            if(a.at(i+1) >= num){
                a.at(i+1) -= num;
            }
            else{
                a.at(i+1) = 0;
                a.at(i) -= num - a.at(i+1);
            }
        }
    }
    cout << ans << '\n';
}