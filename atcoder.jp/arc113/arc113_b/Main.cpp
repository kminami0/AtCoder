#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
#define EPSILON 0.00000000000001 // 10^-14
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

ll llpow(ll x, ll y, ll p){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    ll a = llpow(x, y / 2, p);
    return (a * a) % p;
  }
  else{
    ll a = llpow(x, y / 2, p);
    return (a * a * x) % p;
  }
}

int main()
{
    ll A, B, C;
    cin >> A >> B >> C;
    ll a = A % 10;
    vector<ll> v(0);
    v.push_back(a);
    while(true){
        a *= A;
        a %= 10;
        bool flag = false;
        rep(i, sz(v)){
            if(v.at(i) == a){
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
        v.push_back(a);
    }
    ll p = sz(v);
    ll x = llpow(B, C, p);
    x--;
    if(x < 0){
        x += p;
    }
    cout << v.at(x) << '\n';
}