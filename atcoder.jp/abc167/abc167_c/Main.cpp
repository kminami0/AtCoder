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
  ll N, M, X;
  cin >> N >> M >> X;
  vector<ll> C(N);
  vector<vector<ll>> A(N, vector<ll>(M));
  rep(i, N){
    cin >> C.at(i);
    rep(j, M){
      cin >> A.at(i).at(j);
    }
  }
  ll ans = INF;
  rep(i, 1<<12){
    vector<ll> U(M, 0);
    ll money = 0;
    bitset<12> s(i);
    rep(j, N){
      if(s.test(j)){
        money += C.at(j);
        rep(k, M){
          U.at(k) += A.at(j).at(k);
        }
      }
    }
    bool dame = false;
    rep(j, M){
      if(U.at(j) < X){
        dame = true;
        break;
      }
    }
    if(dame){
      continue;
    }
    chmin(ans, money);
  }
  if(ans == INF){
    cout << -1 << endl;
  }
  else{
    cout << ans << endl;
  }
}