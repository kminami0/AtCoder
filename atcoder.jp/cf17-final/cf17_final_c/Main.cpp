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
    vector<ll> D(N);
    rep(i, N) cin >> D.at(i);
    map<ll, ll> c;
    rep(i, 13){
      c[i] = 0;
    }
    rep(i, N){
        c[D.at(i)]++;
    }
    vector<ll> E(0);
    vector<ll> T(N+1);
    ll p = 0;
    rep(i, 13){
        if(c.at(i) >= 3){
            cout << 0 << endl;
            return 0;
        }
        if(c.at(i) == 1){
          E.push_back(i);
        }
        if(c.at(i) == 2){
          T.at(p) = i;
          T.at(p+1) = 24-i;
          p += 2;
        }
    }
    ll ans = 0;
    T.at(N) = 0;
    rep(i, 1<<(N-p)){
        bitset<26> s(i);
        ll x = INF;
        rep(j, N-p){
          if(s.test(j)){
            T.at(p+j) = 24 - E.at(j);
          }
          else{
            T.at(p+j) = E.at(j);
          }
          if(T.at(p+j) == 24){
            T.at(p+j) = 0;
          }
        }
        rep(j, N+1){
          rep2(k, j+1, N+1){
            ll d = abs(T.at(j) - T.at(k));
            chmin(x, min(d, 24-d));
          }
        }
        if(x == 24){
          x = 0;
        }
        chmax(ans, x);
    }
    cout << ans << endl;
}