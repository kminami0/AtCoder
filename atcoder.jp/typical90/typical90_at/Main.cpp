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
    ll N;
    cin >> N;
    vector<ll> A(46, 0), B(46, 0), C(46, 0);
    rep(i, N){
        ll x;
        cin >> x;
        A.at(x%46)++;
    }
    rep(i, N){
        ll x;
        cin >> x;
        B.at(x%46)++;
    }
    rep(i, N){
        ll x;
        cin >> x;
        C.at(x%46)++;
    }
    ll ans = 0;
    rep(i, 46){
        rep(j, 46){
            ll rem = 46 - i - j;
            if(rem < 0){
                rem += 46;
            }
            rem %= 46;
            ans += A.at(i) * B.at(j) * C.at(rem);
        }
    }
    cout << ans << '\n';
}