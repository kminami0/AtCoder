#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
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
    string S;
    ll K;
    cin >> S >> K;
    vector<ll> dots(sz(S)+1, 0);
    rep(i, sz(S)){
        if(S.at(i) == '.'){
            dots.at(i+1) = dots.at(i) + 1;
        }
        else{
            dots.at(i+1) = dots.at(i);
        }
    }
    ll ans = 0;
    rep(i, sz(S)){
        if(i > 0 && S.at(i-1) == 'X'){
            continue;
        }
        if(S.at(i) == '.'){
            auto iter = lower_bound(all(dots), dots.at(i+1)+K);
            ll dist = iter - begin(dots);
            chmax(ans, dist - i - 1);
        }
        else{
            auto iter = lower_bound(all(dots), dots.at(i+1)+K+1);
            ll dist = iter - begin(dots);
            chmax(ans, dist - i - 1);
        }
    }
    cout << ans << '\n';
}