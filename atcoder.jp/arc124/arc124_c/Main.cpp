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
    ll N;
    cin >> N;
    vector<ll> a(N), b(N);
    rep(i, N){
        cin >> a.at(i) >> b.at(i);
    }
    vector<ll> d = enum_div(a.at(0));
    vector<ll> e = enum_div(b.at(0));
    ll ans = 1;
    for(ll x : d){
        for(ll y : e){
            rep(i, N-1){
                if(!((a.at(i+1) % x == 0 && b.at(i+1) % y == 0) || (b.at(i+1) % x == 0 && a.at(i+1) % y == 0))){
                    break;
                }
                if(i == N-2){
                    chmax(ans, lcm(x, y));
                }
            }
        }
    }
    cout << ans << '\n';
}