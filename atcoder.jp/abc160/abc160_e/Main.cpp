#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
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
  ll X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<ll> p(A), q(B), r(C);
  priority_queue<pair<ll, ll>> apple;
  rep(i, A){
    cin >> p.at(i);
    apple.push(make_pair(p.at(i), 0));
  }
  rep(i, B){
    cin >> q.at(i);
    apple.push(make_pair(q.at(i), 1));
  }
  rep(i, C){
    cin >> r.at(i);
  }
  sort(all(p));
  sort(all(q));
  sort(all(r));
  reverse(all(p));
  reverse(all(q));
  reverse(all(r));
  vector<ll> sred(A+1, 0);
  vector<ll> sgrn(B+1, 0);
  vector<ll> snon(C+1, 0);
  rep(i, A){
    sred.at(i+1) = sred.at(i) + p.at(i);
  }
  rep(i, B){
    sgrn.at(i+1) = sgrn.at(i) + q.at(i);
  }
  rep(i, C){
    snon.at(i+1) = snon.at(i) + r.at(i);
  }
  ll reat = 0;
  ll geat = 0;
  ll taste = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> ate;
  rep(i, X){
    ate.push(make_pair(p.at(i), 0));
  }
  rep(i, Y){
    ate.push(make_pair(q.at(i), 1));
  }
  taste = sred.at(X) + sgrn.at(Y);
  rep(i, C){
    ll bad = ate.top().first;
    if(r.at(i) > bad){
      taste += r.at(i) - bad;
      ate.pop();
    }
    else{
      break;
    }
  }
  cout << taste << endl;
}