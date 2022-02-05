#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
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
    ll n;
    cin >> n;
    if(n == 1){
        cout << "Yes" << '\n';
    }
    else if(n == 2){
        cout << "No" << '\n';
    }
    else if(n == 3){
        cout << "No" << '\n';
    }
    else if(n == 4){
        cout << "No" << '\n';
    }
    else{
        cout << "Yes" << '\n';
    }
}