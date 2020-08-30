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
    ll H, W;
    cin >> H >> W;
    vector<ll> A(H), B(H);
    rep(i, H){
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
    }
    map<ll, ll> from;
    multiset<ll> vals;
    rep(i, W){
      from[i] = i;
      vals.insert(0);
    }
    rep(i, H){
      auto it = from.lower_bound(A.at(i));
      ll mr = -1;
      while(it != from.end() && it->first <= B.at(i)){
        chmax(mr, it->second);
        ll x = it->first - it->second;
        vals.erase(vals.find(x));
        from.erase(it++);
      }
      if(mr != -1 && B.at(i) < W){
        vals.insert(B.at(i) - mr);
        from[B.at(i)] = mr;
      }
      ll ans = -1;
      if(sz(vals) > 0){
        ans = *vals.begin() + i + 1;
      }
      cout << ans << endl;
    }
}