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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

int main()
{
    ll A, B;
    cin >> A >> B;
    ll M = B-A;
    while(true){
        ll r = A % M;
        ll x;
        if(r == 0){
            x = A;
        }
        else{
            x = A + (M-r);
        }
        if(x + M <= B){
            cout << M << '\n';
            return 0;
        }
        M--;
    }
}