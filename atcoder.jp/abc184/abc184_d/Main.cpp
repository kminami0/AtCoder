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
    ll A, B, C;
    cin >> A >> B >> C;
    vector<vector<vector<long double>>> dp(101, vector<vector<long double>>(101, vector<long double>(101, 0)));
    rep(i, 100){
        rep(j, 100){
            rep(k, 100){
                dp.at(99-i).at(99-j).at(99-k) = (long double)(99-i)/(long double)(297-(i+j+k)) * (dp.at(100-i).at(99-j).at(99-k) + 1) + (long double)(99-j)/(long double)(297-(i+j+k)) * (dp.at(99-i).at(100-j).at(99-k) + 1) + (long double)(99-k)/(long double)(297-(i+j+k)) * (dp.at(99-i).at(99-j).at(100-k) + 1);
            }
        }
    }
    cout << fixed << setprecision(9);
    cout << dp.at(A).at(B).at(C) << endl;
}