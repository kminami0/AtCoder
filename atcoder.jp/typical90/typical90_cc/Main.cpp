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
    vector<ll> A(N), B(N);
    vector<vector<ll>> sch(5001, vector<ll>(5001));
    rep(i, N){
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
        sch.at(A.at(i)).at(B.at(i))++;
    }
    vector<vector<ll>> acc(5002, vector<ll>(5002, 0));
    rep(i, 5001){
        rep(j, 5001){
            acc.at(i+1).at(j+1) = acc.at(i).at(j+1) + acc.at(i+1).at(j) - acc.at(i).at(j) + sch.at(i).at(j);
        }
    }
    ll ans = 0;
    rep(i, 5001-K){
        rep(j, 5001-K){
            ll tmp = acc.at(i+K+1).at(j+K+1) - acc.at(i).at(j+K+1) - acc.at(i+K+1).at(j) + acc.at(i).at(j);
            chmax(ans, tmp);
        }
    }
    cout << ans << '\n';
}