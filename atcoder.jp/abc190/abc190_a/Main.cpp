#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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
    ll A, B, C;
    cin >> A >> B >> C;
    if(C == 0){
        if(A <= B){
            cout << "Aoki" << '\n';
        }
        else{
            cout << "Takahashi" << '\n';
        }
    }
    else{
        if(B <= A){
            cout << "Takahashi" << '\n';
        }
        else{
            cout << "Aoki" << '\n';
        }
    }
}