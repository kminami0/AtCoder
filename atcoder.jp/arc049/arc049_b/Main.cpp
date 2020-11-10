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
    ll N;
    cin >> N;
    vector<long double> x(N), y(N), c(N);
    rep(i, N){
      cin >> x.at(i) >> y.at(i) >> c.at(i);
    }
    //t秒で動ける範囲を重ね合わせ、空でない交わりができる最小のtが答え
    //二分探索で境界を求める
    long double l = 0;
    long double r = 300000000;
    rep(i, 100){
      long double ct = (l+r) / 2;
      pair<long double, long double> width = {x.at(0)-ct/c.at(0), x.at(0)+ct/c.at(0)};
      pair<long double, long double> height = {y.at(0)-ct/c.at(0), y.at(0)+ct/c.at(0)};
      rep2(j, 1, N){
        chmax(width.first, x.at(j)-ct/c.at(j));
        chmin(width.second, x.at(j)+ct/c.at(j));
        chmax(height.first, y.at(j)-ct/c.at(j));
        chmin(height.second, y.at(j)+ct/c.at(j));
        if(width.first > width.second || height.first > height.second){
          l = ct;
          break;
        }
        if(j == N-1){
          r = ct;
        }
      }
    }
    cout << fixed << setprecision(15);
    cout << r << endl;   
}