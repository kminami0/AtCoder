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

ll lpow(ll x, ll y){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    ll a = lpow(x, y / 2);
    return a * a;
  }
  else{
    ll a = lpow(x, y / 2);
    return a * a * x;
  }
}

int main()
{
    ll N, D;
    cin >> N >> D;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    ll ans = lpow(2, D);
    rep2(i, 1, 1 << N){
        bitset<20> s(i);
        ll x = 0;
        rep(j, N){
            if(s.test(j)){
                x |= A.at(j);
            }
        }
        bitset<60> t(x);
        ll cnt = lpow(2, D - t.count());
        if(s.count() % 2 == 1){
            ans -= cnt;
        }
        else{
            ans += cnt;
        }
    }
    cout << ans << '\n';
}