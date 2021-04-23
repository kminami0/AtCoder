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
int main()
{
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    rep(i, 10000){
        rep(j, i+1){
            ll b = B * (i-j);
            ll d = C - B;
            if((N-A*j-b) % d == 0 && (N-A*j-b) / d <= i-j && 0 <= (N-A*j-b) / d){
                cout << i << '\n';
                return 0;
            }
        }
    }
}