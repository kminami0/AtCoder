#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14 100兆
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

int main(){
  ll n;
  cin >> n;
  vector<ll> c(n);
  vector<ll> goishi(n, 0);
  ll p = 0;
  rep(i, n){
    ll c;
    cin >> c;
    if(i % 2 == 0){
      if(c == 0){
        if(p % 2 == 0){
          goishi.at(p)++;
        }
        else{
          p++;
          goishi.at(p)++;
        }
      }
      else{
        if(p % 2 == 1){
          goishi.at(p)++;
        }
        else{
          p++;
          goishi.at(p)++;
        }
      }
    }
    else{
      if(p % 2 == c){
        goishi.at(p)++;
      }
      else{
        if(p == 0){
          goishi.at(1) = goishi.at(0) + 1;
          goishi.at(0) = 0;
          p = 1;
        }
        else{
          goishi.at(p-1) += goishi.at(p) + 1;
          goishi.at(p) = 0;
          p--;
        }
      }
    }
  }
  ll ans = 0;
  rep(i, (n+1)/2){
    ans += goishi.at(i*2);
  }
  cout << ans << endl;
}