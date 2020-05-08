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
};

vector<vector<edge>> graph;
vector<ll> cost(5000, INF);
vector<vector<ll>> d(5000, vector<ll>(5000, INF));
queue<ll> q;
vector<ll> C(5000, 0), R(5000, 0);
ll N;

void bfs(ll x, ll y, ll s){
  if(chmin(d.at(s).at(x), d.at(s).at(y)+1)){
    q.push(x);
  }
}

void dijkstra(ll x){
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> r;
  r.push(make_pair(0, x));
  while(!r.empty()){
    pair<ll, ll> p = r.top();
    r.pop();
    rep(i, N){
      if(d.at(p.second).at(i) > R.at(p.second)){
        continue;
      }
      if(chmin(cost.at(i), cost.at(p.second)+C.at(p.second))){
        r.push(make_pair(cost.at(i), i));
      }
    }
  }
}

int main(){
  ll K;
  cin >> N >> K;
  graph.resize(N);
  rep(i, N){
    cin >> C.at(i) >> R.at(i);
  }
  vector<ll> A(K), B(K);
  rep(i, K){
    cin >> A.at(i) >> B.at(i);
    A.at(i)--;
    B.at(i)--;
    graph.at(A.at(i)).push_back({B.at(i)});
    graph.at(B.at(i)).push_back({A.at(i)});
  }
  rep(i, N){
    d.at(i).at(i) = 0;
  }
  rep(i, N){
    q.push(i);
    while(!q.empty()){
      ll p = q.front();
      q.pop();
      rep(j, sz(graph.at(p))){
        bfs(graph.at(p).at(j).to, p, i);
      }
    }
  }
  cost.at(0) = 0;
  dijkstra(0);
  cout << cost.at(N-1) << endl;
}