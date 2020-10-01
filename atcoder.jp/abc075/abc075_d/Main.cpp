#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 5*1000000000000000000 // 5*10^18
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
    vector<pair<ll, ll>> P(N);
    rep(i, N){
        ll x, y;
        cin >> x >> y;
        P.at(i) = {x, y};
    }
    sort(all(P));
    vector<pair<ll, ll>> y(N);
    rep(i, N){
        y.at(i) = {P.at(i).second, i};
    }
    sort(all(y));
    vector<vector<ll>> acc(N+1, vector<ll>(N+1, 0));
    rep(i, N){
        rep(j, N){
            if(P.at(i).second == y.at(j).first){
                acc.at(i+1).at(j+1) = acc.at(i+1).at(j) + acc.at(i).at(j+1) - acc.at(i).at(j) + 1;
            }
            else{
                acc.at(i+1).at(j+1) = acc.at(i+1).at(j) + acc.at(i).at(j+1) - acc.at(i).at(j);
            }
        }
    }
    ll ans = INF;
    rep(i, N){
        rep(j, N){
            rep2(k, i+1, N+1){
                rep2(l, j+1, N+1){
                    if(acc.at(k).at(l) - acc.at(i).at(l) - acc.at(k).at(j) + acc.at(i).at(j) >= K){
                        chmin(ans, (P.at(k-1).first-P.at(i).first)*(y.at(l-1).first-y.at(j).first));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}