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
    ll N;
    cin >> N;
    vector<vector<vector<ll>>> F(N, vector<vector<ll>>(5, vector<ll>(2)));
    rep(i, N){
        rep(j, 5){
            rep(k, 2){
                cin >> F.at(i).at(j).at(k);
            }
        }
    }
    vector<vector<ll>> P(N, vector<ll>(11));
    rep(i, N){
        rep(j, 11){
            cin >> P.at(i).at(j);
        }
    }
    ll ans = -INF;
    rep2(i, 1, 1 << 10){
        bitset<10> s(i);
        vector<ll> cnt(N, 0);
        rep(j, 10){
            if(s.test(j)){
                rep(k, N){
                    if(F.at(k).at(j/2).at(j%2) == 1){
                        cnt.at(k)++;
                    }
                }
            }
        }
        ll inv = 0;
        rep(j, N){
            inv += P.at(j).at(cnt.at(j));
        }
        chmax(ans, inv);
    }
    cout << ans << '\n';
}