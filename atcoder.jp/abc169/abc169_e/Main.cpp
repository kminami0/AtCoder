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
  vector<ll> A(N), B(N);
  vector<pair<ll, ll>> C(N);
  vector<pair<ll, ll>> D(N);
  rep(i, N){
    cin >> A.at(i) >> B.at(i);
  }
  sort(all(A));
  sort(all(B));
  if(N % 2 == 1){
    cout << B.at((N-1)/2) - A.at((N-1)/2) + 1 << endl;
  }
  else{
    cout << (B.at(N/2-1) + B.at(N/2)) - (A.at(N/2-1) + A.at(N/2)) + 1 << endl;
  }
}
