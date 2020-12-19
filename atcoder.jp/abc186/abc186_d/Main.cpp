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
    sort(all(A));
    reverse(all(A));
    vector<ll> acc(N+1, 0);
    rep(i, N){
        acc.at(i+1) = acc.at(i) + A.at(i);
    }
    vector<ll> sacc(N+2, 0);
    rep(i, N+1){
        sacc.at(i+1) = sacc.at(i) + acc.at(i);
    }
    ll ans = 0;
    rep(i, N-1){
        ans += (N-i-1) * A.at(i);
    }
    ans -= (N-1) * acc.at(N) - sacc.at(N);
    cout << ans << endl;
}