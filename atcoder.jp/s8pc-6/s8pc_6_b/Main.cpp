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
  cin >> N;
  vector<ll> A(N), B(N);
  rep(i, N){
    cin >> A.at(i) >> B.at(i);
  }
  ll ans = INF * 100LL;
  rep(i, N){
    rep(j, N){
      ll s = 0;
      rep(k, N){
        ll t = min(max(A.at(k)-A.at(i), A.at(i)-A.at(k))+B.at(k)-A.at(k)+max(B.at(j)-B.at(k), B.at(k)-B.at(j)), max(B.at(k)-A.at(i), A.at(i)-B.at(k))+B.at(k)-A.at(k)+max(B.at(j)-A.at(k), A.at(k)-B.at(j)));
        s += t;
      }
      chmin(ans, s);
    }
  }
  cout << ans << endl;
}