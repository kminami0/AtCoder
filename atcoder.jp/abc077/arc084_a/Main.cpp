#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000099
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
  cin >> N;
  vector<ll> A(N+2), B(N+2), C(N+2);
  rep(i, N){
    cin >> A.at(i);
  }
  A.at(N) = 0;
  A.at(N+1) = INF;
  rep(i, N){
    cin >> B.at(i);
  }
  B.at(N) = 0;
  B.at(N+1) = INF;
  rep(i, N){
    cin >> C.at(i);
  }
  C.at(N) = 0;
  C.at(N+1) = INF;
  sort(all(A));
  sort(all(B));
  sort(all(C));
  ll ans = 0;
  rep2(i, 1, N+1){
    ll l = 0;
    ll r = N+1;
    // A.at(l) < B.at(i) <= A.at(r)
    while(r-l>1){
      ll c = (l+r)/2;
      if(A.at(c) < B.at(i)){
        l = c;
      }
      else{
        r = c;
      }
    }
    ll l2 = 0;
    ll r2 = N+1;
    // C.at(l2) <= B.at(i) < C.at(r2)
    while(r2-l2 > 1){
      ll c2 = (l2 + r2) / 2;
      if(C.at(c2) <= B.at(i)){
        l2 = c2;
      }
      else{
        r2 = c2;
      }
    }
    ans += l * (N-r2+1);
  }
  cout << ans << endl;
}