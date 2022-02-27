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
    string S;
    cin >> N >> S;
    string T = "";
    rep(i, sz(S)){
        if(S.at(i) == 'A'){
            T += "BB";
        }
        else{
            T += S.at(i);
        }
    }
    string U = "";
    rep(i, sz(T)){
        if(i < sz(T)-1 && T.at(i) == 'B' && T.at(i+1) == 'B'){
            U += "A";
            i++;
        }
        else{
            U += T.at(i);
        }
    }
    cout << U << '\n';
}