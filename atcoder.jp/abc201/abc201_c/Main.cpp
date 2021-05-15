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
    string S;
    cin >> S;
    set<ll> onum, xnum;
    rep(i, 10){
        if(S.at(i) == 'o'){
            onum.insert(i);
        }
        else if(S.at(i) == 'x'){
            xnum.insert(i);
        }
    }
    ll ans = 0;
    rep(i, 10000){
        ll pw = i;
        set<ll> used;
        rep(j, 4){
            used.insert(pw % 10);
            pw /= 10;
        }
        bool ok = true;
        for(ll n : onum){
            if(!used.count(n)){
                ok = false;
            }
        }
        for(ll n : xnum){
            if(used.count(n)){
                ok = false;
            }
        }
        if(ok){
            ans++;
        }
    }
    cout << ans << '\n';
}