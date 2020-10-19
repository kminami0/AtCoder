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

bool isPower(ll x, ll y){ // xがyの冪か判定する
    if(x == 1){
        return true;
    }
    if(x % y != 0){
        return false;
    }
    return isPower(x, x/y);
}

int main()
{
    ll N;
    cin >> N;
    // Kが[1でないN-1の約数] or Kが[1でないN/K-1の約数] or Kが[1でないN/(k^2)-1の約数] or ...
    // K * d + 1 = N or K * (K * d + 1) = N or K^2 * (K * d + 1) = N or ...
    ll cnt = sz(enum_div(N-1)) - 1; //1でないN-1の約数の個数
    vector<ll> ediv = enum_div(N);
    for(auto p : ediv){ //Nの約数でループを回す
        if(p == 1){ //1はスキップ
            continue;
        }
        ll q = p;
        while(N / q > 0 && N % q == 0){ //Nの約数のべきqがNの約数である間ループを回す
            if((N / q - 1) % p == 0){ 
                cnt++;
            }
            if(q <= N / p){ //オーバーフロー対策
                q *= p;
            }
            else{
                break;
            }
        }
    }
    cout << cnt << endl;
}