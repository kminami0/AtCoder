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
  vector<vector<ll>> A(N, vector<ll>(N));
  rep(i, N){
    rep(j, N){
      cin >> A.at(i).at(j);
    }
  }
  set<pair<ll, ll>> S;
  rep(i, N){
    rep2(j, i+1, N){
      S.insert(make_pair(i, j));
    }
  }
  rep(k, N){
    rep(i, N){
      rep2(j, i+1, N){
        if(k == i || k == j){
          continue;
        }
        if(A.at(i).at(j) > A.at(i).at(k)+A.at(k).at(j)){
          cout << -1 << endl;
          return 0;
        }
        if(A.at(i).at(j) == A.at(i).at(k)+A.at(k).at(j)){
          S.erase(make_pair(i, j));
        }
      }
    }
  }
  ll ans = 0;
  for(auto x : S){
    ans += A.at(x.first).at(x.second);
  }
  cout << ans << endl;
}