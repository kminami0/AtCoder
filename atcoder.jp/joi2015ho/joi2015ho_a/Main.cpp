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
  vector<ll> P(M);
  rep(i, M){
    cin >> P.at(i);
    P.at(i)--;
  }
  vector<ll> A(N-1), B(N-1), C(N-1);
  rep(i, N-1){
    cin >> A.at(i) >> B.at(i) >> C.at(i);
  }
  vector<ll> s(N, 0), t(N, 0), u(N, 0);
  rep(i, N-1){
    s.at(i+1) = s.at(i) + A.at(i);
    t.at(i+1) = t.at(i) + B.at(i);
    u.at(i+1) = u.at(i) + C.at(i);
  }
  vector<ll> imos(N, 0);
  rep(i, M-1){
    if(P.at(i) < P.at(i+1)){
      imos.at(P.at(i))++;
      imos.at(P.at(i+1))--;
    }
    else{
      imos.at(P.at(i+1))++;
      imos.at(P.at(i))--;
    }
  }
  rep(i, N-1){
    imos.at(i+1) += imos.at(i);
  }
  vector<bool> ic(N-1, false);
  ll ans = 0;
  rep(i, N-1){
    if((A.at(i)-B.at(i))*imos.at(i) > C.at(i)){
      ans += B.at(i) * imos.at(i) + C.at(i);
    }
    else{
      ans += A.at(i) * imos.at(i);
    }
  }
  cout << ans << endl;
}