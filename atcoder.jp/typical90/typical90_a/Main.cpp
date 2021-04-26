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
    ll N, L, K;
    cin >> N >> L >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    ll l = 0;
    ll r = L;
    //スコアはl以上にでき、r以上にできない
    while(r-l > 1){
        ll c = (l+r) / 2;
        ll cnt = 0;
        ll pre = 0;
        rep(i, N){
            if(A.at(i) - pre >= c){
                pre = A.at(i);
                cnt++;
            }
            if(cnt == K){
                break;
            }
        }
        if(cnt == K && L - pre >= c){
            l = c;
        }
        else{
            r = c;
        }
    }
    cout << l << '\n';
}