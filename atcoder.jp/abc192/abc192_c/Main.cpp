#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
#define EPSILON 0.00000000000001 // 10^-14
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

ll g1(ll x){
    string s = to_string(x);
    sort(all(s));
    reverse(all(s));
    return stoll(s);
}

ll g2(ll x){
    string s = to_string(x);
    sort(all(s));
    return stoll(s);
}

int main()
{
    ll N, K;
    cin >> N >> K;
    ll ans = N;
    rep(i, K){
        ans = g1(ans) - g2(ans);
    }
    cout << ans << '\n';
}