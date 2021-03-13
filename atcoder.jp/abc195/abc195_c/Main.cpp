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
    ll N;
    cin >> N;
    ll ans = 0;
    rep2(i, 1, 7){
        if(pow(10, 3*i) <= N){
            ans += (pow(10, 3*i)-pow(10, 3*i-3)) * (i-1);
        }
        else{
            ans += (N - pow(10, 3*i-3) + 1) * (i-1);
            break;
        }
    }
    cout << ans << '\n';
}