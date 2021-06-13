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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    rep(i, Q){
        ll K;
        cin >> K;
        ll l = 0;
        ll r = INF;
        while(r-l>1){
            ll c = (l+r)/2;
            auto iter = upper_bound(all(A), c);
            ll num = iter - begin(A); // c以下の要素の個数
            if(c - num >= K){
                r = c;
            }
            else{
                l = c;
            }
        }
        cout << r << '\n';
    }
}