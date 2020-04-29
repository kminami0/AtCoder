#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
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

vector<vector<ll>> dp(2001, vector<ll>(2001, 0));
//dp.at(l).at(r)はケーキの残りが[l, r)のときにJOIくんの手番であったとき、
//そこからJOIくんがとれるケーキの最大量
vector<vector<ll>> dp2(2001, vector<ll>(2001, 0));
//dp2.at(l).at(r)はケーキの[l, r)がとられたときにJOIくんの手番であって、
//そこからJOIくんがとれる最大量

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N){
    cin >> A.at(i);
  }
  rep(i, N){
    dp.at(i).at(i+1) = A.at(i);
  }
  dp2.at(0).at(N-1) = A.at(N-1);
  dp2.at(1).at(N) = A.at(0);
  rep2(i, 2, N+1){
    rep(l, N+1-i){
      if(A.at(l+1) >= A.at(l+i-1) && A.at(l) >= A.at(l+i-2)){
        dp.at(l).at(l+i) = max(A.at(l)+dp.at(l+2).at(l+i), A.at(l+i-1)+dp.at(l+1).at(l+i-1));
      }
      if(A.at(l+1) >= A.at(l+i-1) && A.at(l) <= A.at(l+i-2)){
        dp.at(l).at(l+i) = max(A.at(l)+dp.at(l+2).at(l+i), A.at(l+i-1)+dp.at(l).at(l+i-2));
      }
      if(A.at(l+1) <= A.at(l+i-1) && A.at(l) >= A.at(l+i-2)){
        dp.at(l).at(l+i) = max(A.at(l)+dp.at(l+1).at(l+i-1), A.at(l+i-1)+dp.at(l+1).at(l+i-1));
      }
      if(A.at(l+1) <= A.at(l+i-1) && A.at(l) <= A.at(l+i-2)){
        dp.at(l).at(l+i) = max(A.at(l)+dp.at(l+1).at(l+i-1), A.at(l+i-1)+dp.at(l).at(l+i-2));
      }
    }
  }
  rep2(i, 2, N+1){
    rep(l, i+1){
      if(l == 0){
        dp2.at(0).at(N-i) = dp.at(N-i).at(N);
      }
      else if(l == i){
        dp2.at(i).at(N) = dp.at(0).at(i);
      }
      else if(l == 1 && i == 2){
        if(A.at(0) > A.at(N-1)){
          dp2.at(1).at(N-1) = A.at(0);
        }
        else{
          dp2.at(1).at(N-1) = A.at(N-1);
        }
      }
      else if(l == 1){
        if(A.at(N+1-i) >= A.at(N-1) && A.at(0) >= A.at(N+2-i)){
          dp2.at(1).at(N+1-i) = max(A.at(0)+dp.at(N+2-i).at(N), A.at(N+1-i)+dp.at(N+2-i).at(N));
        }
        if(A.at(N+1-i) >= A.at(N-1) && A.at(0) <= A.at(N+2-i)){
          dp2.at(1).at(N+1-i) = max(A.at(0)+dp.at(N+2-i).at(N), A.at(N+1-i)+dp2.at(1).at(N+3-i));
        }
        if(A.at(N+1-i) <= A.at(N-1) && A.at(0) >= A.at(N+2-i)){
          dp2.at(1).at(N+1-i) = max(A.at(0)+dp.at(N+1-i).at(N-1), A.at(N+1-i)+dp.at(N+2-i).at(N));
        }
        if(A.at(N+1-i) <= A.at(N-1) && A.at(0) <= A.at(N+2-i)){
          dp2.at(1).at(N+1-i) = max(A.at(0)+dp.at(N+1-i).at(N-1), A.at(N+1-i)+dp2.at(1).at(N+3-i));
        }
      }
      else if(l == i-1){
        if(A.at(l-2) >= A.at(N-1) && A.at(0) >= A.at(l-1)){
          dp2.at(l).at(N-1) = max(A.at(l-1)+dp2.at(l-2).at(N-1), A.at(N-1)+dp.at(1).at(l));
        }
        if(A.at(l-2) >= A.at(N-1) && A.at(0) <= A.at(l-1)){
          dp2.at(l).at(N-1) = max(A.at(l-1)+dp2.at(l-2).at(N-1), A.at(N-1)+dp.at(0).at(l-1));
        }
        if(A.at(l-2) <= A.at(N-1) && A.at(0) >= A.at(l-1)){
          dp2.at(l).at(N-1) = max(A.at(l-1)+dp.at(0).at(l-1), A.at(N-1)+dp.at(1).at(l));
        }
        if(A.at(l-2) <= A.at(N-1) && A.at(0) <= A.at(l-1)){
          dp2.at(l).at(N-1) = max(A.at(l-1)+dp.at(0).at(l-1), A.at(N-1)+dp.at(0).at(l-1));
        }
      }
      else{
        if(A.at(l-2) >= A.at(N+l-i) && A.at(l-1) >= A.at(N+l-i+1)){
          dp2.at(l).at(N+l-i) = max(A.at(l-1)+dp2.at(l-2).at(N+l-i), A.at(N+l-i)+dp2.at(l-1).at(N+l-i+1));
        }
        if(A.at(l-2) >= A.at(N+l-i) && A.at(l-1) <= A.at(N+l-i+1)){
          dp2.at(l).at(N+l-i) = max(A.at(l-1)+dp2.at(l-2).at(N+l-i), A.at(N+l-i)+dp2.at(l).at(N+l-i+2));
        }
        if(A.at(l-2) <= A.at(N+l-i) && A.at(l-1) >= A.at(N+l-i+1)){
          dp2.at(l).at(N+l-i) = max(A.at(l-1)+dp2.at(l-1).at(N+l-i+1), A.at(N+l-i)+dp2.at(l-1).at(N+l-i+1));
        }
        if(A.at(l-2) <= A.at(N+l-i) && A.at(l-1) <= A.at(N+l-i+1)){
          dp2.at(l).at(N+l-i) = max(A.at(l-1)+dp2.at(l-1).at(N+l-i+1), A.at(N+l-i)+dp2.at(l).at(N+l-i+2));
        }
      }
    }
  }
  ll ans = dp.at(0).at(N);
  rep(i, N+1){
    chmax(ans, dp2.at(i).at(i));
  }
  cout << ans << endl;
}