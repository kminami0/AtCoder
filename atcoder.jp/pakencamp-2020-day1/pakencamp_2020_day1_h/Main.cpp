#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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
    ll T;
    cin >> T;
    rep(i, T){
      ll A, B, C;
      cin >> A >> B >> C;
      if(((A & B) == B) && ((A & C) == C) && (((B & C) == B) || ((B & C) == 0))){
        cout << "Yes" << endl;
      }
      else{
        cout << "No" << endl;
      }
    }
}