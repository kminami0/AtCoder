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
    ll N, K;
    cin >> N >> K;
    vector<priority_queue<ll>> neta(N);
    rep(i, N){
        ll t, d;
        cin >> t >> d;
        t--;
        neta.at(t).push(d);
    }
    vector<ll> sushif(0);
    vector<ll> sushis(0);
    rep(i, N){
        ll p = sz(neta.at(i));
        rep(j, p){
            if(j == 0){
                sushif.emplace_back(neta.at(i).top());
            }
            else{
                sushis.emplace_back(neta.at(i).top());
            }
            neta.at(i).pop();
        }
    }
    sort(rbegin(sushif), rend(sushif));
    sort(rbegin(sushis), rend(sushis));
    ll ans = 0;
    vector<ll> accf(sz(sushif)+1, 0);
    vector<ll> accs(sz(sushis)+1, 0);
    rep(i, sz(sushif)){
        accf.at(i+1) = accf.at(i) + sushif.at(i);
    }
    rep(i, sz(sushis)){
        accs.at(i+1) = accs.at(i) + sushis.at(i);
    }
    rep(i, min(ll(sz(sushif)), K)){
        if(K-(i+1) >= sz(accs)){
            continue;
        }
        chmax(ans, accf.at(i+1)+accs.at(K-(i+1)) + (i+1)*(i+1));
    }
    cout << ans << '\n';
}