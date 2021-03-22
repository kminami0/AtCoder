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
    ll N, K;
    cin >> N >> K;
    vector<long double> a(N);
    rep(i, N) cin >> a.at(i);
    vector<long double> b(N);
    rep(i, N) cin >> b.at(i);
    sort(all(a));
    sort(all(b));
    ll l = 0;
    ll r = INF;
    //l以下の数はK個未満しかなく、r以下の数はK個以上ある
    while(r-l > 1){
        ll c = (l+r) / 2;
        ll cnt = 0;
        for(ll x : a){
            auto it = upper_bound(all(b), c/x);
            cnt += end(b) - it;
        }
        if(N*N-cnt < K){
            l = c;
        }
        else{
            r = c;
        }
    }
    cout << r << '\n';
}