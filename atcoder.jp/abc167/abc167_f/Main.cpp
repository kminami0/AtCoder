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
  ll N;
  cin >> N;
  vector<string> S(N);
  rep(i, N){
    cin >> S.at(i);
  }
  vector<pair<ll, ll>> d(N);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> r;
  priority_queue<pair<ll, ll>> q;
  rep(i, N){
    ll c = 0;
    ll m = 0;
    rep(j, sz(S.at(i))){
      if(S.at(i).at(j) == '('){
        c++;
      }
      else{
        c--;
        chmin(m, c);
      }
    }
    d.at(i) = make_pair(m, c);
    if(c > 0){
      q.push(d.at(i));
    }
    else{
      r.push(make_pair(m-c, -c));
    }
  }
  ll now = 0;
  while(!q.empty()){
    pair<ll, ll> p = q.top();
    q.pop();
    if(now + p.first < 0){
      cout << "No" << endl;
      return 0;
    }
    now += p.second;
  }
  while(!r.empty()){
    pair<ll, ll> p = r.top();
    r.pop();
    if(now + p.first-p.second < 0){
      cout << "No" << endl;
      return 0;
    }
    now -= p.second;
  }
  if(now != 0){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
  }
}