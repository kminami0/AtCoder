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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

ll ngcd(vector<ll> a){
    ll res;
    res = a.at(0);
    for(ll i = 1; i < a.size() && res != 1; i++) {
        res = gcd(a.at(i), res);
    }
    return res;
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
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> d(N-1), e(N-1);
    d.at(0) = A.at(0);
    e.at(0) = A.at(N-1);
    rep(i, N-2){
        d.at(i+1) = gcd(d.at(i), A.at(i+1));
        e.at(i+1) = gcd(e.at(i), A.at(N-i-2));
    }
    ll ans = 0;
    rep(i, N){
        if(i == 0){
            chmax(ans, e.at(N-2));
        }
        else if(i == N-1){
            chmax(ans, d.at(N-2));
        }
        else{
            chmax(ans, gcd(d.at(i-1), e.at(N-i-2)));
        }
    }
    cout << ans << endl;
}