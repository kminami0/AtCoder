#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000009
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
  ll N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N){
    cin >> A.at(i);
  }
  A.push_back(-2000000000000000009);
  A.push_back(2000000000000000009);
  sort(all(A));
  ll l = -1000000000000000009;
  ll r = 1000000000000000009;
  while(r-l > 1){
    ll c = (l+r)/2;
    ll cnt = 0;
    rep2(i, 1, N+1){
      if(A.at(i) < 0){
        ll l2 = 0;
        ll r2 = N+1;
        while(r2-l2 > 1){
          if(A.at(i) * A.at((l2+r2)/2) > c){
            l2 = (l2+r2)/2;
          }
          else{
            r2 = (l2+r2)/2;
          }
        }
        if(i >= r2){
          cnt += N - r2 + 1;
          cnt -= i - r2 + 1;
        }
        else{
          cnt += N - r2 + 1;
        }
      }
      if(A.at(i) == 0){
        if(c >= 0){
          cnt += N-i;
        }
      }
      if(A.at(i) > 0){
        ll l2 = 0;
        ll r2 = N+1;
        while(r2-l2 > 1){
          if(A.at(i) * A.at((l2+r2)/2) <= c){
            l2 = (l2+r2)/2;
          }
          else{
            r2 = (l2+r2)/2;
          }
        }
        if(i <= l2){
          cnt += l2;
          cnt -= i;
        }
      }
    }
    if(cnt >= K){
      r = c;
    }
    else{
      l = c;
    }
  }
  cout << r << endl;
}