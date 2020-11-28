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
int main()
{
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll fm = min(y, x*2);
    if(a == b){
        cout << x << endl;
    }
    else if(a > b){
        cout << x + (a-b-1)*fm << endl;
    }
    else{
        cout << x + (b-a)*fm << endl;
    }
}