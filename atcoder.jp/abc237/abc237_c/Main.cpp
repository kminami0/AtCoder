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
    string S;
    cin >> S;
    ll p = 0;
    ll q = 0;
    rep(i, sz(S)){
        if(S.at(i) != 'a'){
            p = i;
            break;
        }
        if(i == ll(sz(S))-1){
            cout << "Yes" << '\n';
            return 0;
        }
    }
    rep(i, sz(S)){
        if(S.at(sz(S)-1-i) != 'a'){
            q = i;
            break;
        }
    }
    if(p > q){
        cout << "No" << '\n';
        return 0;
    }
    string T = S.substr(p, sz(S)-p-q);
    string U = T;
    reverse(all(U));
    if(T == U){
        cout << "Yes" << '\n';
    }
    else{
        cout << "No" << '\n';
    }
}