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
  ll N, Q;
  cin >> N >> Q;
  vector<ll> a(N, -1), b(N);
  rep(i, N){
    b.at(i) = i;
  }
  rep(i, Q){
    ll f, t, x;
    cin >> f >> t >> x;
    f--;
    t--;
    x--;
    ll tmp = a.at(x);
    a.at(x) = b.at(t);
    b.at(t) = b.at(f);
    b.at(f) = tmp;
  }
  vector<ll> p(N);
  rep(i, N){
    ll d = b.at(i);
    while(d != -1){
      p.at(d) = i;
      d = a.at(d);
    }
  }
  rep(i, N){
    cout << p.at(i) + 1 << endl;
  }
}