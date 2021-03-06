#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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
    vector<ll> d(N);
    ll maxans = 0;
    ll maxdis = 0;
    rep(i, N){
      cin >> d.at(i);
      maxans += d.at(i);
      chmax(maxdis, d.at(i));
    }
    cout << maxans << endl;
    cout << max(maxdis - (maxans - maxdis), 0LL) << endl;
}