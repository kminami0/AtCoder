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
    vector<ll> A(N), B(N);
    rep(i, N){
        cin >> A.at(i) >> B.at(i);
    }
    vector<ll> score(0);
    rep(i, N){
        score.push_back({B.at(i)});
        score.push_back({A.at(i)-B.at(i)});
    }
    sort(all(score));
    reverse(all(score));
    ll ans = 0;
    rep(i, K){
        ans += score.at(i);
    }
    cout << ans << '\n';
}