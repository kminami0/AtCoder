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

ll lpow(ll x, ll y){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    ll a = lpow(x, y / 2);
    return a * a;
  }
  else{
    ll a = lpow(x, y / 2);
    return a * a * x;
  }
}

int main()
{
    string N;
    ll K;
    cin >> N >> K;
    rep(i, K){
        ll num = 0;
        reverse(all(N));
        rep(j, sz(N)){
            num += (N.at(j)-'0') * lpow(8, j);
        }
        string M = "";
        while(num > 0){
            M += (num%9) + '0';
            num /= 9;
        }
        if(M == ""){
            M = "0";
        }
        reverse(all(M));
        rep(j, sz(M)){
            if(M.at(j) == '8'){
                M.at(j) = '5';
            }
        }
        N = M;
    }
    cout << N << '\n';
}