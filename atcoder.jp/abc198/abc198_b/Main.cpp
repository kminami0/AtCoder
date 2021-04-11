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
    ll N;
    cin >> N;
    if(N == 0){
      cout << "Yes" << '\n';
      return 0;
    }
    while(N % 10 == 0){
        N /= 10;
    }
    string S = to_string(N);
    rep(i, sz(S)){
        if(S.at(i) != S.at(sz(S)-1-i)){
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';
}