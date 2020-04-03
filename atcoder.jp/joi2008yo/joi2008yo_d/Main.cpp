#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000099
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
  ll m;
  cin >> m;
  vector<ll> sx(m), sy(m);
  rep(i, m){
    cin >> sx.at(i) >> sy.at(i);
  }
  ll n;
  cin >> n;
  vector<ll> px(n), py(n);
  set<pair<ll, ll>> P;
  rep(i, n){
    cin >> px.at(i) >> py.at(i);
    P.insert(make_pair(px.at(i), py.at(i)));
  }
  if(m == 1){
    cout << px.at(0)-sx.at(0) << " " << py.at(0)-sy.at(0) << endl;
    return 0;
  }
  for(auto p : P){
    ll dx = p.first-sx.at(0);
    ll dy = p.second-sy.at(0);
    rep2(i, 1, m){
      if(!P.count(make_pair(sx.at(i)+dx, sy.at(i)+dy))){
        break;
      }
      if(i == m-1){
        cout << dx << " " << dy << endl;
        return 0;
      }
    }
  }
}