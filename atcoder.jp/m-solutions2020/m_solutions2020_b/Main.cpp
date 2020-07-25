#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
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
  ll A, B, C, K;
  cin >> A >> B >> C >> K;
  rep(i, K){
    if(C <= B){
      C *= 2;
    }
    else if(B <= A){
      B *= 2;
    }
  }
  if(A < B && B < C){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}