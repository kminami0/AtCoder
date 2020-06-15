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
    vector<ll> D(A.at(N-1)+1);
    rep(i, N){
      ll c = A.at(i);
      while (c <= A.at(N-1)){
        D.at(c)++;
        c += A.at(i);
      }
    }
    ll ans = 0;
    rep(i, N){
      if(D.at(A.at(i)) == 1){
        ans++;
      }
    }
    cout << ans << endl;
}