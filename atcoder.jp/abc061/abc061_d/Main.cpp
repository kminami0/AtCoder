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
  ll N, M;
  cin >> N >> M;
  vector<ll> a(M), b(M), c(M);
  rep(i, M){
    cin >> a.at(i) >> b.at(i) >> c.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  vector<ll> d(N, -1 * INF);
  d.at(0) = 0;
  ll cnt = 0;
  while(true){
    bool update = false;
    rep(i, M){
      if(d.at(b.at(i)) < d.at(a.at(i)) + c.at(i)){
        d.at(b.at(i)) = d.at(a.at(i)) + c.at(i);
        update = true;
      }
    }
    if(!update){
      break;
    }
    cnt++;
    if(cnt == N-1){
      break;
    }
  }
  vector<bool> positive(N, false);
  rep(i, N){
    rep(i, M){
      if(d.at(b.at(i)) < d.at(a.at(i)) + c.at(i)){
        d.at(b.at(i)) = d.at(a.at(i)) + c.at(i);
        positive.at(b.at(i)) = true;
      }
      if(positive.at(a.at(i))){
        positive.at(b.at(i)) = true;
      }
    }
  }
  if(positive.at(N-1)){
    cout << "inf" << endl;
  }
  else{
    cout << d.at(N-1) << endl;
  }
}