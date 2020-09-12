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
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i, N) cin >> a.at(i);
    vector<ll> acc(N+1, 0);
    rep(i, N){
        acc.at(i+1) = acc.at(i) + a.at(i);
    }
    vector<vector<ll>> beauty(N, vector<ll>(N, 0));
    rep(i, N){
        rep2(j, i, N){
            beauty.at(i).at(j) = acc.at(j+1) - acc.at(i);
        }
    }
    ll ans = 0;
    ll cnt = 0;
    rep(i, 40){
      rep(j, N){
        rep2(k, j, N){
          bitset<41> s(ans + (1LL<< (39-i)));
          bitset<41> r(beauty.at(j).at(k));
          if((s & r) == s){
            cnt++;
          }
        }
      }
      if(cnt >= K){
        ans += (1LL<< (39-i));
      }
      cnt = 0;
    }
    cout << ans << endl;
}