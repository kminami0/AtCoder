#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
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
int main()
{
    long double d;
    cin >> d;
    if(d - floor(d) <= 0.2 + EPSILON){
        cout << floor(d) << "-" << endl;
    }
    else if(d - floor(d) <= 0.6 + EPSILON){
        cout << floor(d) << endl;
    }
    else{
        cout << floor(d) << "+" << endl;
    }
}