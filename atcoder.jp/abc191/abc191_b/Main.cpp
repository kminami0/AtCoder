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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> B(0);
    rep(i, N){
        if(A.at(i) != X){
            B.emplace_back(A.at(i));
        }
    }
    rep(i, sz(B)-1){
        cout << B.at(i) << ' ';
    }
    if(sz(B) >= 1){
        cout << B.at(sz(B)-1) << '\n';
    }
    else{
        cout << '\n';
    }
}