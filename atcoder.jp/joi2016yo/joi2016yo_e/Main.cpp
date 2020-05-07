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

struct edge {
  ll to;
};

vector<vector<edge>> graph;
ll N, K, P, Q;
vector<ll> d(100000, INF);
queue<ll> q;
vector<ll> cost(100000, INF);
set<ll> danger;
set<ll> zombie;

void bfs(ll x, ll y){
  if(chmin(d.at(x), d.at(y)+1)){
    q.push(x);
  }
}

void dijkstra(ll x){
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> r;
  r.push(make_pair(0, x));
  while(!r.empty()){
    pair<ll, ll> p = r.top();
    r.pop();
    rep(i, sz(graph.at(p.second))){
      if(zombie.count(graph.at(p.second).at(i).to)){
        continue;
      }
      if(graph.at(p.second).at(i).to == N-1){
        if(chmin(cost.at(graph.at(p.second).at(i).to), cost.at(p.second))){
          r.push(make_pair(cost.at(graph.at(p.second).at(i).to), graph.at(p.second).at(i).to));
        }
      }
      else if(danger.count(graph.at(p.second).at(i).to)){
        if(chmin(cost.at(graph.at(p.second).at(i).to), cost.at(p.second)+Q)){
          r.push(make_pair(cost.at(graph.at(p.second).at(i).to), graph.at(p.second).at(i).to));
        }
      }
      else{
        if(chmin(cost.at(graph.at(p.second).at(i).to), cost.at(p.second)+P)){
          r.push(make_pair(cost.at(graph.at(p.second).at(i).to), graph.at(p.second).at(i).to));
        }
      }
    }
  }
}
        

int main(){
  ll M, S;
  cin >> N >> M >> K >> S >> P >> Q;
  graph.resize(N);
  vector<ll> C(K);
  rep(i, K){
    cin >> C.at(i);
    C.at(i)--;
    q.push(C.at(i));
    d.at(C.at(i)) = 0;
    zombie.insert(C.at(i));
  }
  vector<ll> A(M), B(M);
  rep(i, M){
    cin >> A.at(i) >> B.at(i);
    A.at(i)--;
    B.at(i)--;
    graph.at(A.at(i)).push_back({B.at(i)});
    graph.at(B.at(i)).push_back({A.at(i)});
  }
  while(!q.empty()){
    ll p = q.front();
    q.pop();
    rep(j, sz(graph.at(p))){
      bfs(graph.at(p).at(j).to, p);
    }
  }
  rep(i, N){
    if(d.at(i) <= S){
      danger.insert(i);
    }
  }
  cost.at(0) = 0;
  dijkstra(0);
  cout << cost.at(N-1) << endl;
}