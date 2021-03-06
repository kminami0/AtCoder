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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    map<ll, ll> bucket;
    rep(i, M){
        bucket[A.at(i)]++;
    }
    ll ans = 0;
    rep(i, M+1){
        if(bucket[i] == 0){
            ans = i;
            break;
        }
    }
    rep(i, N-M){
        bucket[A.at(i)]--;
        bucket[A.at(M+i)]++;
        if(bucket[A.at(i)] == 0){
            chmin(ans, A.at(i));
        }
    }
    cout << ans << '\n';
}