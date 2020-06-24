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

vector<ll> dp(100000, 0);

int main()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a.at(i);
    dp.at(1) = abs(a.at(1) - a.at(0));
    rep(i, N-2){
        dp.at(i+2) = min(dp.at(i+1) + abs(a.at(i+2) - a.at(i+1)), dp.at(i) + abs(a.at(i+2) - a.at(i)));
    }
    cout << dp.at(N-1) << endl;
}