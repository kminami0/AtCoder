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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll N;
    cin >> N;
    vector<ll> a(3*N);
    rep(i, 3*N) cin >> a.at(i);
    priority_queue<ll, vector<ll>, greater<ll>> q;
    priority_queue<ll> r;
    vector<ll> sum1(N+1, 0);
    vector<ll> sum2(N+1, 0);
    rep(i, N){
        q.push(a.at(i));
        sum1.at(0) += a.at(i);
    }
    rep(i, N){
        sum1.at(i+1) = sum1.at(i);
        q.push(a.at(N+i));
        sum1.at(i+1) += a.at(N+i);
        ll p = q.top();
        q.pop();
        sum1.at(i+1) -= p;
    }
    rep(i, N){
        r.push(a.at(3*N-1-i));
        sum2.at(0) += a.at(3*N-1-i);
    }
    rep(i, N){
        sum2.at(i+1) = sum2.at(i);
        r.push(a.at(2*N-1-i));
        sum2.at(i+1) += a.at(2*N-1-i);
        ll p = r.top();
        r.pop();
        sum2.at(i+1) -= p;
    }
    ll ans = -INF;
    rep(i, N+1){
        chmax(ans, sum1.at(i)-sum2.at(N-i));
    }
    cout << ans << '\n';
}