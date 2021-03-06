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
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    ll ans = INF;
    rep(i, 1 << (N-1)){
        bitset<19> s(i);
        vector<ll> tmp(0);
        ll x = 0;
        rep(j, N-1){
            x = x | A.at(j);
            if(s.test(j)){
                tmp.emplace_back(x);
                x = 0;
            }
        }
        x = x | A.at(N-1);
        tmp.emplace_back(x);
        ll y = 0;
        rep(j, sz(tmp)){
            y = y ^ tmp.at(j);
        }
        chmin(ans, y);
    }
    cout << ans << '\n';
}