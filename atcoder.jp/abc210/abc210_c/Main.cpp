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
    ll N, K;
    cin >> N >> K;
    vector<ll> c(N);
    rep(i, N) cin >> c.at(i);
    map<ll, ll> candy;
    ll kind = 0;
    rep(i, K-1){
        if(!candy.count(c.at(i))){
            kind++;
        }
        candy[c.at(i)]++;
    }
    ll ans = 0;
    rep(i, N-K+1){
        if(!candy.count(c.at(i+K-1)) || candy.at(c.at(i+K-1)) == 0){
            kind++;
        }
        candy[c.at(i+K-1)]++;
        chmax(ans, kind);
        candy.at(c.at(i))--;
        if(candy.at(c.at(i)) == 0){
            kind--;
        }
    }
    cout << ans << '\n';
}