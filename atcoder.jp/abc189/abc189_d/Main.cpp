#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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

ll lpower(ll x, ll y){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    ll a = lpower(x, y / 2);
    return a * a;
  }
  else{
    ll a = lpower(x, y / 2);
    return a * a * x;
  }
}

ll calc(ll N, vector<string> S){
    if(N == 0){
        return 1;
    }
    if(S.at(N-1) == "AND"){
        return calc(N-1, S);
    }
    return lpower(2LL, N) + calc(N-1, S);
}

int main()
{
    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i, N){
        cin >> S.at(i);
    }
    cout << calc(N, S) << '\n';
}