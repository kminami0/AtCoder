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
    ll N, X;
    string S;
    cin >> N >> X >> S;
    stack<char> P;
    rep(i, N){
        if(S.at(i) == 'U'){
            if(!P.empty() && P.top() != 'U'){
                P.pop();
            }
            else{
                P.push(S.at(i));
            }
        }
        else{
            P.push(S.at(i));
        }
    }
    string T = "";
    while(!P.empty()){
        char x = P.top();
        T += x;
        P.pop();
    }
    reverse(all(T));
    for(char x : T){
        if(x == 'U'){
            X /= 2;
        }
        else if(x == 'L'){
            X *= 2;
        }
        else{
            X = 2*X+1;
        }
    }
    cout << X << '\n';
}