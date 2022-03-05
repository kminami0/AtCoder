#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
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
    ll A, B, C, X;
    cin >> A >> B >> C >> X;
    if(X <= A){
        cout << 1 << '\n';
        return 0;
    }
    if(X > B){
        cout << 0 << '\n';
        return 0;
    }
    long double ans = (long double)(C)/(long double)(B-A);
    cout << fixed << setprecision(20);
    cout << ans << '\n';
}