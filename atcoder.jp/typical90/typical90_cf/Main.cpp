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
    string S;
    cin >> N >> S;
    vector<ll> v(0);
    ll p = 1;
    rep(i, N-1){
        if(S.at(i) == S.at(i+1)){
            p++;
        }
        else{
            v.push_back(p);
            p = 1;
        }
    }
    v.push_back(p);
    ll cnt = 0;
    for(ll n : v){
        cnt += n * (n - 1) / 2;
    }
    cout << N * (N - 1) / 2 - cnt << '\n';
}