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
    long double T, L, X, Y, Q;
    cin >> T >> L >> X >> Y >> Q;
    cout << fixed << setprecision(12);
    rep(i, Q){
        long double E;
        cin >> E;
        long double alpha = 2.0 * M_PI * E / T;
        long double y = - L / 2.0 * sin(alpha);
        long double z = L / 2.0 - L / 2.0 * cos(alpha);
        long double theta = asin(z / pow(X*X+(Y-y)*(Y-y)+z*z, 0.5));
        theta *= 180.0 / M_PI;
        cout << theta << '\n';
    }
}