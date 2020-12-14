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
    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> h(N);
    rep(i, N) cin >> h.at(i);
    ll l = 0;
    ll r = 1e9;
    while(r-l > 1){
        ll c = (l+r) / 2;
        vector<ll> rem(0);
        rep(i, N){
            if(h.at(i) > B*c){
                rem.push_back(h.at(i) - B*c);
            }
        }
        ll cnt = 0;
        for(ll p : rem){
            cnt += (p+A-B-1) / (A-B);
        }
        if(cnt > c){
            l = c;
        }
        else{
            r = c;
        }
    }
    cout << r << endl;
}