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
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  ll sum = 0;
  rep(i, N){
    cin >> A.at(i);
    sum += A.at(i);
  }
  ll pop = 0;
  rep(i, N){
    if(4 * M * A.at(i) >= sum){
      pop++;
    }
  }
  if(pop >= M){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}