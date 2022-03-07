#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    ll ans = 0;
    map<ll, ll> mi, mx;
    rep(i, K){
        ll r = ans % N;
        if(mi.count(r)){
            ll p = i-mi.at(r);
            if((K-i) % p == 0){
                ans += (ans - mx.at(r)) * ((K-i) / p);
                break;
            }
        }
        mi[r] = i;
        mx[r]  = ans;
        ans += A.at(ans % N);
    }
    cout << ans << '\n';
}