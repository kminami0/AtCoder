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
    ll X, N;
    cin >> X >> N;
    vector<ll> p(N);
    rep(i, N) cin >> p.at(i);
    set<ll> P;
    rep(i, N){
      P.insert(p.at(i));
    }
    if(!P.count(X)){
      cout << X << endl;
      return 0;
    }
    ll i = 1;
    while(true){
      if(!P.count(X-i)){
        cout << X-i << endl;
        return 0;
      }
      if(!P.count(X+i)){
        cout << X+i << endl;
        return 0;
      }
      i++;
    }
}