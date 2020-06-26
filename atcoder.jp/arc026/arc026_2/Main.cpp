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

vector<ll> enum_div(ll n){
    vector<ll> ret;
    for(ll i = 1 ; i*i <= n ; ++i){
        if(n%i == 0){
            ret.push_back(i);
           if(i != 1 && i*i != n){
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
    if(N == 1){
        cout << "Deficient" << endl;
        return 0;
    }
    vector<ll> d = enum_div(N);
    ll s = 0;
    rep(i, sz(d)){
        s += d.at(i);
    }
    if(s == N){
        cout << "Perfect" << endl;
    }
    else if(s < N){
        cout << "Deficient" << endl;
    }
    else{
        cout << "Abundant" << endl;
    }
}