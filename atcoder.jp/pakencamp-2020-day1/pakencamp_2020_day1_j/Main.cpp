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
  vector<tuple<ll, ll, ll>> ans(0);
  rep2(i, 1, 100001){
    ll a = (i+1)*(i+1) - i*i;
    ll b = 2*(i+1)*i;
    ll c = (i+1)*(i+1) + i*i;
    ans.push_back({a, b, c});
  }
  rep(i, 100000){
    cout << get<0>(ans.at(i)) << " " << get<1>(ans.at(i)) << " " << get<2>(ans.at(i)) << endl;
  }
}