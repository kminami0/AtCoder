#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
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
  ll N, M;
  cin >> N >> M;
  vector<ll> P(N+2);
  rep(i, N){
    cin >> P.at(i);
  }
  P.at(N) = 0;
  P.at(N+1) = M + 1;
  vector<ll> X(0);
  rep(i, N+2){
    rep(j, N+2){
      X.push_back(P.at(i)+P.at(j));
    }
  }
  sort(all(X));
  ll score = 0;
  rep(i, (N+2)*(N+2)){
    if(X.at(i) > M){
      break;
    }
    ll l = 0;
    ll r = (N+2)*(N+2)-1;
    // X.at(i) + X.at(l) <= M < X.at(i)+X.at(r)
    while(r-l > 1){
      ll c = (l+r)/2;
      if(X.at(i) + X.at(c) <= M){
        l = c;
      }
      else{
        r = c;
      }
    }
    chmax(score, X.at(i) + X.at(l));
  }
  cout << score << endl;
}