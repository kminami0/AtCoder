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
    ll N;
    cin >> N;
    ll x = 1;
    ll i = 0;
    while(x <= N){
      x *= 2;
      i++;
    }
    if(i % 2 == 1){
      x = 1;
      i = 0;
      while(x <= N){
        if(i % 2 == 0){
          x = 2 * x + 1;
        }
        else{
          x *= 2;
        }
        i++;
      }
      if(i % 2 == 1){
        cout << "Aoki" << endl;
        return 0;
      }
    }
    x = 1;
    i = 0;
    while(x <= N){
      if(i % 2 == 0){
        x *= 2;
      }
      else{
        x = 2 * x + 1;
      }
      i++;
    }
    if(i % 2 == 1){
      x = 1;
      i = 0;
      while(x <= N){
        x = 2 * x + 1;
        i++;
      }
      if(i % 2 == 1){
        cout << "Aoki" << endl;
        return 0;
      }
    }
    cout << "Takahashi" << endl;
}