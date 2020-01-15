#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000000
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
  vector<ll> a(M), b(M);
  rep(i, M){
    cin >> a.at(i) >> b.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  vector<pair<ll, ll>> req(M);
  rep(i, M){
    req.at(i).first = b.at(i);
    req.at(i).second = a.at(i);
  }
  sort(all(req));
  ll cnt = 0;
  ll last = -1;
  rep(i, M){
    if(req.at(i).second >= last){
      cnt++;
      last = req.at(i).first;
    }
  }
  cout << cnt << endl;
}