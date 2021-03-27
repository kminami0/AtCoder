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
    ll N;
    long double x, y, z, w;
    cin >> N >> x >> y >> z >> w;
    long double cx, cy;
    cx = (x+z) / 2;
    cy = (y+w) / 2;
    long double dx = x - cx;
    long double dy = y - cy;
    long double ansx = dx * cos(2*M_PI/N) - dy * sin(2*M_PI/N);
    long double ansy = dx * sin(2*M_PI/N) + dy * cos(2*M_PI/N);
    ansx += cx;
    ansy += cy;
    cout << fixed << setprecision(11);
    cout << ansx << " " << ansy << '\n';
}