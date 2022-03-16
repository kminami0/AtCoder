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
    ll N;
    cin >> N;
    vector<ll> p(N);
    rep(i, N){
        cin >> p.at(i);
        p.at(i)--;
    }
    vector<ll> a(N), b(N);
    a.at(0) = 1;
    b.at(N-1) = 1;
    rep(i, N-1){
        a.at(i+1) = a.at(i) + 999899999/(N-1);
        b.at(N-i-2) = b.at(N-i-1) + 999899999/(N-1);
    }
    rep(i, N-1){
        b.at(p.at(i+1)) += i+1;
    }
    rep(i, N-1){
        cout << a.at(i) << ' ';
    }
    cout << a.at(N-1) << '\n';
    rep(i, N-1){
        cout << b.at(i) << ' ';
    }
    cout << b.at(N-1) << '\n';
}