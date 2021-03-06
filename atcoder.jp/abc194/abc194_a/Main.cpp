#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll A, B;
    cin >> A >> B;
    A += B;
    if(A >= 15 && B >= 8){
        cout << 1 << '\n';
    }
    else if(A >= 10 && B >= 3){
        cout << 2 << '\n';
    }
    else if(A >= 3){
        cout << 3 << '\n';
    }
    else
    {
        cout << 4 << '\n';
    }
    
}