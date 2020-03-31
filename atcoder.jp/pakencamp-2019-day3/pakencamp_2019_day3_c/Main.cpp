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
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> A(N, vector<ll>(M));
  rep(i, N){
    rep(j, M){
      cin >> A.at(i).at(j);
    }
  }
  vector<vector<ll>> score(M, vector<ll>(M, 0));
  rep(i, M){
    rep2(j, i+1, M){
      rep(k, N){
        score.at(i).at(j) += max(A.at(k).at(i), A.at(k).at(j));
      }
    }
  }
  ll ans = 0;
  rep(i, M){
    rep2(j, i+1, M){
      chmax(ans, score.at(i).at(j));
    }
  }
  cout << ans << endl;
}