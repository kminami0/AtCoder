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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    ll inconv = 0;
    vector<ll> diff(N-1);
    rep(i, N-1){
        diff.at(i) = A.at(i)-A.at(i+1);
        inconv += abs(A.at(i)-A.at(i+1));
    }
    rep(i, Q){
        ll L, R, V;
        cin >> L >> R >> V;
        L--;
        if(L >= 1){
            inconv -= abs(diff.at(L-1));
            diff.at(L-1) -= V;
            inconv += abs(diff.at(L-1));
        }
        if(R <= N-1){
            inconv -= abs(diff.at(R-1));
            diff.at(R-1) += V;
            inconv += abs(diff.at(R-1));
        }
        cout << inconv << '\n';
    }
}