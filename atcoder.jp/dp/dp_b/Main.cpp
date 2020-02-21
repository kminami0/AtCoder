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

vector<ll> dp(100000, INF);
//dp.at(i)は足場i+1にたどり着く最小コスト

int main(){
  ll N, K;
  cin >> N >> K;
  vector<ll> h(N);
  rep(i, N){
    cin >> h.at(i);
  }
  dp.at(0) = 0;
  rep(i, N){
    rep2(j, 1, min((int)K, i)+1){
      chmin(dp.at(i), dp.at(i-j)+abs(h.at(i)-h.at(i-j)));
    }
  }
  cout << dp.at(N-1) << endl;
}