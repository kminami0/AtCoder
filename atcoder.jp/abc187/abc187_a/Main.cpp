#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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
    ll A, B;
    cin >> A >> B;
    ll a = 0;
    a += A % 10;
    A /= 10;
    a += A % 10;
    A /= 10;
    a += A % 10;
    ll b = 0;
    b += B % 10;
    B /= 10;
    b += B % 10;
    B /= 10;
    b += B % 10;
    if(a >= b){
        cout << a << endl;
    }
    else{
        cout << b << endl;
    }
}