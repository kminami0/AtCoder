#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    rep(i, N-1){
        if(i * C - (N - 1 - i) * D <= B - A && B - A <= i * D - (N - 1 - i) * C){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}