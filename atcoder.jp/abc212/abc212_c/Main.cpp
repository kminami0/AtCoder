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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> B(M);
    rep(i, M) cin >> B.at(i);
    sort(all(A));
    sort(all(B));
    ll ans = INF;
    rep(i, N){
        auto iter = lower_bound(all(B), A.at(i));
        if(iter - begin(B) < M){
            chmin(ans, *iter-A.at(i));
        }
        if(iter - 1 - begin(B) >= 0){
            iter--;
            chmin(ans, A.at(i)-*iter);
        }
    }
    cout << ans << '\n';
}