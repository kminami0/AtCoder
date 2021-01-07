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
    ll X, Y;
    cin >> X >> Y;
    if(X == 0 && Y == 0){
      cout << "1 1" << endl;
    }
    else if(Y < X){
      cout << X << " " << 2*X+Y << endl;
    }
    else if(X < Y){
      cout << X+2*Y << " " << Y << endl;
    }
    else{
      cout << -1 << endl;
    }
}