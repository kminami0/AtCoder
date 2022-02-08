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
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    if((A + Y - 1) / Y + (B + Y - 1) / Y + (C + Y - 1) / Y <= X){
        cout << "Yes" << '\n';
        return 0;
    }
    if((A + X - 1) / X + (B + X - 1) / X + (C + X - 1) / X <= Y){
        cout << "Yes" << '\n';
        return 0;
    }
    ll w = (A + Y - 1) / Y;
    if(w < X && (B + (X-w) - 1) / (X-w) + (C + (X-w) - 1) / (X-w) <= Y){
        cout << "Yes" << '\n';
        return 0;
    }
    w = (B + Y - 1) / Y;
    if(w < X && (C + (X-w) - 1) / (X-w) + (A + (X-w) - 1) / (X-w) <= Y){
        cout << "Yes" << '\n';
        return 0;
    }
    w = (C + Y - 1) / Y;
    if(w < X && (A + (X-w) - 1) / (X-w) + (B + (X-w) - 1) / (X-w) <= Y){
        cout << "Yes" << '\n';
        return 0;
    }
    w = (A + X - 1) / X;
    if(w < Y && (B + (Y-w) - 1) / (Y-w) + (C + (Y-w) - 1) / (Y-w) <= X){
        cout << "Yes" << '\n';
        return 0;
    }
    w = (B + X - 1) / X;
    if(w < Y && (C + (Y-w) - 1) / (Y-w) + (A + (Y-w) - 1) / (Y-w) <= X){
        cout << "Yes" << '\n';
        return 0;
    }
    w = (C + X - 1) / X;
    if(w < Y && (A + (Y-w) - 1) / (Y-w) + (B + (Y-w) - 1) / (Y-w) <= X){
        cout << "Yes" << '\n';
        return 0;
    }
    cout << "No" << '\n';
}