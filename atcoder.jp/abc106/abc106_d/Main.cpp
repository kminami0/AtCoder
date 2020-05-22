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
  ll N, M, Q;
  cin >> N >> M >> Q;
  vector<ll> L(M), R(M), p(Q), q(Q);
  rep(i, M){
    cin >> L.at(i) >> R.at(i);
  }
  rep(i, Q){
    cin >> p.at(i) >> q.at(i);
  }
  vector<vector<ll>> d(N+1, vector<ll>(N+1, 0));
  // d.at(i).at(j)は都市iから出発してjで運行を終える列車の数
  rep(j, M){
    d.at(L.at(j)).at(R.at(j))++;
  }
  vector<vector<ll>> s(N+1, vector<ll>(N+1, 0));
  // s.at(i).at(j)は都市iから出発してjまでに運行を終える列車の数
  rep(i, N){
    rep(j, N){
      s.at(i+1).at(j+1) = s.at(i+1).at(j) + d.at(i+1).at(j+1);
    }
  }
  rep(i, Q){
    ll ans = 0;
    rep2(j, p.at(i), q.at(i)+1){
      ans += s.at(j).at(q.at(i));
    }
    cout << ans << endl;
  }
}