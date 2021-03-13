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
    ll A, B, W;
    cin >> A >> B >> W;
    ll t = 0;
    ll mini = -1;
    ll maxi = -1;
    while(A*t <= 1000*W){
        if(mini == -1){
            if(1000*W <= B*t){
                mini = t;
            }
        }
        if(1000*W <= B*t){
            chmax(maxi, t);
        }
        t++;
    }
    if(maxi == -1){
        cout << "UNSATISFIABLE" << '\n';
    }
    else{
        cout << mini << " " << maxi << '\n';
    }
}