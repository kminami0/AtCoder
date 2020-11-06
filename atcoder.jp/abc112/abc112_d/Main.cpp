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
           if(i*i != n){
               ret.push_back(n/i);
           }
       }
   }
   return ret;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> divisors = enum_div(M);
    sort(all(divisors));
    reverse(all(divisors));
    //Mの約数gのうち、M/gがN-1より大きくなる最大のgが答え
    //そのようなgに対し、数列aとしてg,...,g,M-g*(N-1)がとれる
    rep(i, sz(divisors)){
      if(M / divisors.at(i) <= N-1){
        continue;
      }
      cout << divisors.at(i) << endl;
      return 0;
    }
}