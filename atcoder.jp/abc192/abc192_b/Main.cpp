#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
#define EPSILON 0.00000000000001 // 10^-14
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
    string S;
    cin >> S;
    rep(i, sz(S)){
        if(i % 2 == 0){
            if(isupper(S.at(i))){
                cout << "No" << endl;
                return 0;
            }
        }
        else{
            if(islower(S.at(i))){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}