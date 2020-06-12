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
  ll N, M, R;
  cin >> N >> M >> R;
  vector<ll> r(R);
  rep(i, R){
    cin >> r.at(i);
    r.at(i)--;
  }
  vector<vector<ll>> d(N, vector<ll>(N, INF));
  rep(i, N){
    d.at(i).at(i) = 0;
  }
  rep(i, M){
    ll A, B, C;
    cin >> A >> B >> C;
    A--;
    B--;
    d.at(A).at(B) = C;
    d.at(B).at(A) = C;
  }
  rep(k, N){
    rep(i, N){
      rep(j, N){
        chmin(d.at(i).at(j), d.at(i).at(k) + d.at(k).at(j));
      }
    }
  }
  ll ans = INF;
  sort(all(r));
  do{
    ll tmp = 0;
    rep(i, R-1){
      tmp += d.at(r.at(i)).at(r.at(i+1));
    }
    chmin(ans, tmp);
  } while(next_permutation(all(r)));
  cout << ans << endl;
}