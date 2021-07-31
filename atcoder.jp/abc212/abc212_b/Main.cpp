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
int main()
{
    string X;
    cin >> X;
    if(X.at(0) == X.at(1) && X.at(0) == X.at(2) && X.at(0) == X.at(3)){
        cout << "Weak" << '\n';
        return 0;
    }
    vector<ll> d(4);
    rep(i, 4){
        d.at(i) = X.at(i) - '0';
    }
    if(d.at(1) == (d.at(0)+1) % 10 && d.at(2) == (d.at(1)+1) % 10 && d.at(3) == (d.at(2)+1) % 10){
        cout << "Weak" << '\n';
    }
    else{
        cout << "Strong" << '\n';
    }
}