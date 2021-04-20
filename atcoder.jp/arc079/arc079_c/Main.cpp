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

ll seqmax(vector<ll> a){
    ll c = -INF;
    rep(i, sz(a)){
        chmax(c, a.at(i));
    }
    return c;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) {
        cin >> a.at(i);
    }
    ll ans = 0;
    while(seqmax(a) > N-1){
        ll S = 0;
        rep(i, N){
            S += a.at(i) / N;
        }
        rep(i, N){
            ll b = a.at(i);
            a.at(i) -= (b/N)*N;
            a.at(i) += S - b/N;
        }
        ans += S;
    }
    cout << ans << '\n';
}