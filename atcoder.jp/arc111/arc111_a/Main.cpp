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

ll M;

ll calc(ll x){
  if(x == 0){
    return 1 % (M * M);
  }
  if(x % 2 == 0){
    ll a = calc(x/2);
    return (a * a) % (M * M);
  }
  else{
    ll a = calc(x/2);
    return (a * a * 10) % (M * M);
  }
}

int main()
{
    ll N;
    cin >> N >> M;
    cout << (calc(N) / M) % M << endl;    
}