#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000000 //10^19
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

map<ll, ll> memo;
ll X;

ll f(ll y){
  if(memo.count(y)){
    return memo.at(y);
  }
  if(y == X){
    memo[y] = 0;
    return 0;
  }
  if(y % 2 == 0){
    ll a = f(y / 2) + 1;
    memo[y] = min(a, abs(y-X));
    return memo.at(y);
  }
  else if(y == 1){
    memo[y] = abs(y-X);
    return memo.at(y);
  }
  else{
    ll a = f(y + 1) + 1;
    ll b = f(y - 1) + 1;
    memo[y] = min(min(a, b), abs(y-X));
    return memo.at(y);
  }
}

int main()
{
    ll Y;
    cin >> X >> Y;
    cout << f(Y) << endl;
}