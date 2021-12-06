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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    ll sum = 0;
    rep(i, N){
        sum ^= A.at(i);
    }
    rep(i, N){
        if(A.at(i) == sum){
            cout << "Win" << '\n';
            return 0;
        }
    }
    if(N % 2 == 1){
        cout << "Win" << '\n';
    }
    else{
        cout << "Lose" << '\n';
    }
}