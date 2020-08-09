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
    ll A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A);
    rep(i, A) cin >> s.at(i);
    s.push_back(-1 * INF);
    s.push_back(INF);
    vector<ll> t(B);
    rep(i, B) cin >> t.at(i);
    t.push_back(-1 * INF);
    t.push_back(INF);
    sort(all(s));
    sort(all(t));
    rep(i, Q){
        ll x;
        cin >> x;
        ll l = 0;
        ll r = A+1;
        // s.at(l) <= x < s.at(r);
        while(r-l > 1){
            ll c = (l+r) / 2;
            if(s.at(c) <= x){
                l = c;
            }
            else{
                r = c;
            }
        }
        ll ljinja = s.at(l);
        ll rjinja = s.at(r);
        l = 0;
        r = B+1;
        // t.at(l) <= x < t.at(r);
        while(r-l > 1){
            ll c = (l+r) / 2;
            if(t.at(c) <= x){
                l = c;
            }
            else{
                r = c;
            }
        }
        ll ltera = t.at(l);
        ll rtera = t.at(r);
        ll ans = INF;
        //WW
        ll m = min(ljinja, ltera);
        chmin(ans, x-m);
        //WE
        if(x-ljinja < rtera-x){
            chmin(ans, 2*(x-ljinja)+rtera-x);
        }
        else{
            chmin(ans, 2*(rtera-x)+x-ljinja);
        }
        //EW
        if(x-ltera < rjinja-x){
            chmin(ans, 2*(x-ltera)+rjinja-x);
        }
        else{
            chmin(ans, 2*(rjinja-x)+x-ltera);
        }
        //EE
        m = max(rjinja, rtera);
        chmin(ans, m-x);
        cout << ans << endl;
    }
}