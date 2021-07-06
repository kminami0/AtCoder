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

vector<ll> enum_div(ll n){
    vector<ll> ret;
    for(ll i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
           if(i*i != n){
               ret.push_back(n/i);
           }
       }
   }
   return ret;
}

int main()
{
    ll K;
    cin >> K;
    vector<ll> divs = enum_div(K);
    ll ans = 0;
    for(ll b : divs){
        vector<ll> r = enum_div(K/b);
        sort(all(r));
        for(ll a : r){
            if(a <= b && b <= K/(a*b)){
                ans++;
            }
            else{
                break;
            }
        }
    }
    cout << ans << '\n';
}