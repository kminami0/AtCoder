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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M+2);
    A.at(0) = 0;
    rep(i, M) cin >> A.at(i+1);
    A.at(M+1) = N+1;
    sort(all(A));
    ll width = N;
    rep(i, M+1){
        if(A.at(i+1)-A.at(i)-1 == 0){
            continue;
        }
        chmin(width, A.at(i+1)-A.at(i)-1);
    }
    ll ans = 0;
    rep(i, M+1){
        if(A.at(i+1)-A.at(i)-1 == 0){
            continue;
        }
        ans += (A.at(i+1)-A.at(i)-1 + width - 1) / width;
    }
    cout << ans << endl;
}