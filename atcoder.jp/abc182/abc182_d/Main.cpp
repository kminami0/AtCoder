#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
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
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> acc(N+1, 0);
    ll M = 0;
    ll p = 0;
    ll q = 0;
    vector<ll> max_acc(N+1, 0);
    rep(i, N){
        acc.at(i+1) = acc.at(i) + A.at(i);
    }
    rep(i, N){
        max_acc.at(i+1) = max(max_acc.at(i), acc.at(i+1));
    }
    ll ans = 0;
    ll t = 0;
    rep(i, N){
        chmax(ans, t+max_acc.at(i+1));
        chmax(ans, t+acc.at(i+1));
        t += acc.at(i+1);
    }
    cout << ans << endl;
}