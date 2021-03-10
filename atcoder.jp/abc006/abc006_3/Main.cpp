#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll N, M;
    cin >> N >> M;
    if(M < 2*N || 4*N < M){
        cout << "-1 -1 -1" << '\n';
    }
    else if(2*N <= M && M <= 3*N){
        cout << 3*N-M << " " << M-2*N << " " << 0 << '\n';
    }
    else{
        cout << 0 << " " << 4*N-M << " " << M-3*N << "\n";
    }
}