#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000009
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
  ll n;
  cin >> n;
  vector<ll> x(n), y(n);
  set<pair<ll, ll>> pts;
  rep(i, n){
    cin >> x.at(i) >> y.at(i);
    pts.insert(make_pair(x.at(i), y.at(i)));
  }
  ll ans = 0;
  for(auto p : pts){
    for(auto q : pts){
      pair<ll, ll> v = make_pair(q.first-p.first, q.second-p.second);
      pair<ll, ll> w = make_pair(-1 * v.second, v.first);
      pair<ll, ll> r = make_pair(p.first + w.first, p.second + w.second);
      pair<ll, ll> s = make_pair(q.first + w.first, q.second + w.second);
      if(pts.count(r)){
        if(pts.count(s)){
//          cout << p.first << " " << p.second << endl;
//          cout << q.first << " " << q.second << endl;
//          cout << r.first << " " << r.second << endl;
//          cout << s.first << " " << s.second << endl;
          chmax(ans, v.first*v.first+v.second*v.second);
//          cout << ans << endl;
        }
      }
    }
  }
  cout << ans << endl;
}