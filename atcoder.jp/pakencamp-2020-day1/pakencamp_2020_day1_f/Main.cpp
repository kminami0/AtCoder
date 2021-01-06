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
    ll P;
    cin >> P;
    vector<ll> F(0);
    F.push_back(1);
    F.push_back(1);
    if(P == 1){
      cout << 1 << endl;
      return 0;
    }
    ll i = 0;
    while(i < 100000000){
      F.push_back((F.at(i)+F.at(i+1)) % P);
      if(F.at(sz(F)-1) == 0){
        cout << i+3 << endl;
        return 0;
      }
      i++;
    }
    cout << -1 << endl;
}