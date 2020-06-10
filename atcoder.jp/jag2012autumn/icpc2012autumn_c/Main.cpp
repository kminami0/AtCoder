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

struct edge{
  ll to;
  ll cost;
};
 
vector<edge> graph;
 
vector<ll> par;
vector<ll> rnk;
 
void init(ll n){
  rep(i, n){
    par.at(i) = i;
    rnk.at(i) = 0;
  }
}
 
ll root(ll x){
  if(par.at(x) == x){
    return x;
  }
  else{
    par.at(x) = root(par.at(x));
    return par.at(x);
  }
}
 
bool same(ll x, ll y){
  if(root(x) == root(y)){
    return true;
  }
  else{
    return false;
  }
}
 
void unite(ll x, ll y){
  x = root(x);
  y = root(y);
  if(x == y){
    return;
  }
  if(rnk.at(x) < rnk.at(y)){
    par.at(x) = y;
  }
  else{
    par.at(y) = x;
    if(rnk.at(x) == rnk.at(y)){
      rnk.at(x)++;
    }
  }
}

int main(){
  while(true){
    ll n, m;
    cin >> n >> m;
    if(n == 0 && m == 0){
      return 0;
    }
    graph.resize(n);
    par.resize(n);
    rnk.resize(n);
    init(n);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    vector<ll> s(m), t(m), c(m);
    rep(i, m){
      cin >> s.at(i) >> t.at(i) >> c.at(i);
      s.at(i)--;
      t.at(i)--;
      q.push(make_pair(c.at(i), i));
    }
    vector<ll> eds(0);
    while(!q.empty()){
      pair<ll, ll> p = q.top();
      q.pop();
      if(same(s.at(p.second), t.at(p.second))){
        continue;
      }
      unite(s.at(p.second), t.at(p.second));
      eds.push_back(p.first);
    }
    cout << eds.at((sz(eds)-1)/2) << endl;
  }
}