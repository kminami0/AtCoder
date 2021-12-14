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
    vector<string> ptn = {"oxx", "xxo", "xox"};
    if(sz(S) == 1){
        cout << "Yes" << '\n';
    }
    else if(sz(S) == 2){
        if(S == "ox" || S == "xo" || S == "xx"){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
        }
    }
    else{
        ll p;
        if(S.substr(0, 3) == "oxx"){
            p = 0;
        }
        else if(S.substr(0, 3) == "xxo"){
            p = 1;
        }
        else if(S.substr(0, 3) == "xox"){
            p = 2;
        }
        else{
            cout << "No" << '\n';
            return 0;
        }
        rep(i, sz(S)-2){
            if(S.substr(i, 3) != ptn.at(p%3)){
                cout << "No" << '\n';
                return 0;
            }
            p++;
        }
        cout << "Yes" << '\n';
    }
}