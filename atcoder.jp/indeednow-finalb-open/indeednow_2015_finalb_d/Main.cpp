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
  ll H, W, Sx, Sy, Gx, Gy;
  cin >> H >> W >> Sx >> Sy >> Gx >> Gy;
  vector<vector<ll>> P(W, vector<ll>(H));
  ll ban = 0;
  rep(i, H){
    rep(j, W){
      cin >> P.at(j).at(i);
      ban += P.at(j).at(i);
    }
  }
  graph.resize(W*H);
  par.resize(W*H);
  rnk.resize(W*H);
  init(W*H);
  priority_queue<pair<ll, ll>> q;
  rep(i, H){
    rep(j, W-1){
      q.push(make_pair(P.at(j).at(i)*P.at(j+1).at(i), i*(W-1)+j));
    }
  }
  priority_queue<pair<ll, ll>> tate;
  rep(i, H-1){
    rep(j, W){
      q.push(make_pair(P.at(j).at(i)*P.at(j).at(i+1), i*W+j+H*W));
    }
  }
  ll ans = 0;
  while(!q.empty()){
    pair<ll, ll> p = q.top();
    q.pop();
    if(p.second < H*W){
      ll x = p.second / (W-1);
      ll y = p.second % (W-1);
      if(same(x*W+y, x*W+y+1)){
        continue;
      }
      unite(x*W+y, x*W+y+1);
      ans += p.first;
    }
    else{
      ll x = (p.second-H*W) / W;
      ll y = (p.second-H*W) % W;
      if(same(x*W+y, (x+1)*W+y)){
        continue;
      }
      unite(x*W+y, (x+1)*W+y);
      ans += p.first;
    }
  }
  cout << ans + ban << endl;
}