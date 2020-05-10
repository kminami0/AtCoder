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
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N){
    cin >> A.at(i);
    A.at(i)--;
  }
  if(K < N){
    ll ima = 0;
    rep(i, K){
      ima = A.at(ima);
    }
    cout << ima+1 << endl;
    return 0;
  }
  vector<ll> reach(1, 0);
  set<ll> S;
  S.insert(0);
  ll now = 0;
  ll ls = 0;
  rep(i, N){
    now = A.at(now);
    if(S.count(now)){
      ls = now;
      break;
    }
    S.insert(now);
    reach.push_back(now);
  }
  ll lf = 0;
  rep(i, sz(reach)){
    if(reach.at(i) == ls){
      lf = i;
      break;
    }
  }
  ll lsz = sz(reach)-lf;
  now = 0;
  rep(i, lf){
    now = A.at(now);
  }
  rep(i, (K-lf)%lsz){
    now = A.at(now);
  }
  cout << now+1 << endl;
}