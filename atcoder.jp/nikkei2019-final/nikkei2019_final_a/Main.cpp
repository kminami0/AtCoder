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

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N){
    cin >> A.at(i);
  }
  vector<ll> s(N+1, 0);
  rep(i, N){
    s.at(i+1) = s.at(i) + A.at(i);
  }
  vector<ll> m(N, 0);
  rep(i, N){
    rep(j, N-i){ //区画j+1,...,j+i+1の埋蔵資源量を計算
      chmax(m.at(i), s.at(j+i+1)-s.at(j));
    }
  }
  rep(i, N){
    cout << m.at(i) << endl;
  }
}