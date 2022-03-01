#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
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
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    rep(i, M){
        cin >> a.at(i) >> b.at(i);
    }
    vector<pair<ll, ll>> line(M);
    rep(i, M){
        line.at(i) = {a.at(i), b.at(i)};
    }
    sort(all(line));
    ll s = 0;
    ll t = 1;
    rep(i, M-1){
        if(line.at(i).first == line.at(i+1).first){
            t++;
        }
        else{
            reverse(begin(line)+s, begin(line)+t);
            s = t;
            t++;
        }
    }
    reverse(begin(line)+s, begin(line)+t);
    vector<ll> B(M);
    rep(i, M){
        B.at(i) = line.at(i).second;
    }
    vector<ll> dp(M+1, INF);
    dp.at(0) = 0;
    rep(i, M){
        ll l = 0;
        ll r = M;
        // dp.at(l) <= B.at(i) < dp.at(r);
        while(r-l > 1){
            ll c = (l+r) / 2;
            if(dp.at(c) < B.at(i)){
                l = c;
            }
            else{
                r = c;
            }
        }
        if(dp.at(l) < B.at(i)){
            dp.at(r) = B.at(i);
        }
    }
    ll ans = 0;
    rep(i, M+1){
        if(dp.at(i) == INF){
            break;
        }
        else{
            ans = i;
        }
    }
    cout << ans << '\n';
}