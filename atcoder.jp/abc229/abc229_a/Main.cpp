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
    string S1, S2;
    cin >> S1 >> S2;
    if(S1 == "##" || S2 == "##" || (S1.at(0) == '#' && S2.at(0) == '#') || (S1.at(1) == '#' && S2.at(1) == '#')){
        cout << "Yes" << '\n';
    }
    else{
        cout << "No" << '\n';
    }
}