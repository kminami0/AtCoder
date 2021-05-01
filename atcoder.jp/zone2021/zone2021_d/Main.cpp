#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
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
    string T = "";
    bool rev = false;
    string tmp = "";
    rep(i, sz(S)){
        if(S.at(i) == 'R'){
            rev = !rev;
            reverse(all(tmp));
            T = tmp + T;
            tmp = "";
        }
        else{
            if(rev){
                tmp += S.at(i);
            }
            else{
                T += S.at(i);
            }
        }
    }
    if(rev){
        reverse(all(T));
        T += tmp;
    }
    stack<char> X;
    rep(i, sz(T)){
        if(X.empty()){
            X.push(T.at(i));
        }
        else{
            if(T.at(i) != X.top()){
                X.push(T.at(i));
            }
            else{
                X.pop();
            }
        }
    }
    string ans = "";
    while(!X.empty()){
        char c = X.top();
        ans += c;
        X.pop();
    }
    reverse(all(ans));
    cout << ans << '\n';
}