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
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    sort(all(A));
    reverse(all(A));
    A.push_back(0);
    ll ans = 0;
    ll cnt = 0;
    rep(i, N){
        if(cnt == K){
            break;
        }
        ll d = A.at(i) - A.at(i+1);
        if(d * (i+1) <= K - cnt){
            ans += (d * A.at(i) - (d-1)*d/2) * (i+1);
            cnt += (i+1) * d;
        }
        else{
            ll q = (K-cnt) / (i+1);
            ans += (q * A.at(i) - (q-1)*q/2) * (i+1);
            cnt += (i+1) * q;
            ans += (K-cnt) * (A.at(i)-q);
            cnt += K-cnt;
        }
    }
    cout << ans << '\n';
}