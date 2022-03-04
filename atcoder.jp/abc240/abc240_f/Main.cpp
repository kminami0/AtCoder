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

void solve(){
    ll N, M;
    cin >> N >> M;
    ll b = 0, a = 0;
    ll ans = -INF;
    rep(i, N){
        ll x, y;
        cin >> x >> y;
        chmax(ans, a+b+x);
        if(x < 0 && b > 0){
            ll id = b / -x;
            if(id < y){
                chmax(ans, a+b*id + x*id*(id+1)/2);
            }
        }
        a += b*y + x*y*(y+1)/2;
        b += x*y;
        chmax(ans, a);
    }
    cout << ans << '\n';
}

int main()
{
    ll T;
    cin >> T;
    rep(i, T){
        solve();
    }
}