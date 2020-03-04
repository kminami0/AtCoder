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
  ll N, A, B, C;
  cin >> N >> A >> B >> C;
  vector<ll> D(N);
  rep(i, N){
    cin >> D.at(i);
  }
  sort(all(D));
  reverse(all(D));
  ll ans = 0;
  ll pz = C;
  rep(i, N+1){
    chmax(ans, pz/(A+B*i));
    if(i == N){
      break;
    }
    pz += D.at(i);
  }
  cout << ans << endl;
}