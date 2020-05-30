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

double dis(double x, double y, double a, double b){
  return pow(pow(x-a, 2)+pow(y-b, 2), 0.5);
}

int main(){
  ll N, M;
  cin >> N >> M;
  vector<double> x(N+M), y(N+M), r(N+M, 0);
  rep(i, N){
    cin >> x.at(i) >> y.at(i) >> r.at(i);
  }
  rep(i, M){
    cin >> x.at(N+i) >> y.at(N+i);
  }
  double ans = 2147483647;
  rep(i, N){
    chmin(ans, r.at(i));
  }
  rep(i, M){
    rep(j, N){
      chmin(ans, dis(x.at(j), y.at(j), x.at(N+i), y.at(N+i))-r.at(j));
    }
    rep(j, M){
      if(j == i){
        continue;
      }
      chmin(ans, dis(x.at(N+i), y.at(N+i), x.at(N+j), y.at(N+j)) * 0.5);
    }
  }
  cout << fixed << setprecision(15);
  cout << ans << endl;
}