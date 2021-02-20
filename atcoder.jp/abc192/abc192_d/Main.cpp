#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
#define EPSILON 0.00000000000001 // 10^-14
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

ll llpow(ll x, ll y){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    ll a = llpow(x, y / 2);
    return a * a;
  }
  else{
    ll a = llpow(x, y / 2);
    return a * a * x;
  }
}

//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    string X;
    ll M;
    cin >> X >> M;
    if(sz(X) == 1){
        if(stoll(X) <= M){
            cout << 1 << '\n';
            return 0;
        }
        else{
            cout << 0 << '\n';
            return 0;
        }
    }
    ll d = 0;
    rep(i, sz(X)){
        chmax(d, ll(X.at(i)-'0'));
    }
    ll bound = powl(M, 1.0/(sz(X)-1)) + EPSILON;
    if(sz(X) == 2){
        ll x0 = X.at(0) - '0';
        ll x1 = X.at(1) - '0';
        ll b = (M-x1) / x0;
        if(b < d+1){
            cout << 0 << '\n';
            return 0;
        }
        else{
            cout << b - (d+1) + 1 << '\n';
            return 0;
        }
    }
    if(sz(X) == 3){
        ll x0 = X.at(0) - '0';
        ll x1 = X.at(1) - '0';
        ll x2 = X.at(2) - '0';
        long double r = pow(x1*x1-4*x0*(x0-M), 0.5);
        long double s = (-x1 + r) / (2*x0) + EPSILON;
        ll b = s;
        if(b < d+1){
            cout << 0 << '\n';
            return 0;
        }
        else{
            cout << b - (d+1) + 1 << '\n';
            return 0;
        }
    }
    vector<ll> digit(sz(X));
    rep(i, sz(X)){
        digit.at(i) = X.at(i) - '0';
    }
    ll ans = 0;
    rep2(i, d+1, bound+1){
        ll val = 0;
        rep(j, sz(X)){
            val += llpow(i, sz(X)-1-j) * digit.at(j);
        }
        if(val <= M){
            ans++;
        }
    }
    cout << ans << '\n';
}