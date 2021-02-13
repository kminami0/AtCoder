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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll B, C;
    cin >> B >> C;
    ll x, y, z, w;
    x = B-C/2;
    y = B+max((C-2)/2, 0LL);
    z = -B-(C-1)/2;
    w = -B+(C-1)/2;
    if(B >= 1){
        if(w < x){
            cout << w-z+1 + y-x+1 << '\n';
        }
        else{
            cout << max(w,y) - min(z,x) + 1 << '\n';
        }
    }
    else{
        if(y < z){
            cout << w-z+1 + y-x+1 << '\n';
        }
        else{
            cout << max(w,y) - min(z,x) + 1 << '\n';
        }
    }
}