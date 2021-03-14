#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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
    vector<ll> cnt(N+1, 0);
    rep(i, M){
      ll a, b;
      cin >> a >> b;
      cnt.at(a)++;
      cnt.at(b)++;
    }
    rep(i, N){
      if(cnt.at(i+1) % 2 == 1){
        cout << "NO" << '\n';
        return 0;
      }
    }
    cout << "YES" << '\n';
}