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
  ll time;
};

vector<vector<edge>> graph;
vector<vector<edge>> rgraph; //辺の向きを逆転させたグラフ

map<pair<ll, ll>, ll> cost;
map<pair<ll, ll>, ll> rcost; //辺の向きを逆転させたグラフにおける移動時間

void dijkstra(ll x){
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  q.push(make_pair(0, x));
  while(!q.empty()){
    pair<ll, ll> p = q.top();
    q.pop();
    rep(i, sz(graph.at(p.second))){
      if(cost.count(make_pair(x, graph.at(p.second).at(i).to))){
        if(chmin(cost.at(make_pair(x, graph.at(p.second).at(i).to)), cost.at(make_pair(x, p.second))+graph.at(p.second).at(i).time)){
          q.push(make_pair(cost.at(make_pair(x, graph.at(p.second).at(i).to)), graph.at(p.second).at(i).to));
        }
      }
      else{
        cost[make_pair(x, graph.at(p.second).at(i).to)] = cost.at(make_pair(x, p.second))+graph.at(p.second).at(i).time;
        q.push(make_pair(cost.at(make_pair(x, graph.at(p.second).at(i).to)), graph.at(p.second).at(i).to));
      }
    }
  }
}

void rdijkstra(ll x){
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  q.push(make_pair(0, x));
  while(!q.empty()){
    pair<ll, ll> p = q.top();
    q.pop();
    rep(i, sz(rgraph.at(p.second))){
      if(rcost.count(make_pair(x, rgraph.at(p.second).at(i).to))){
        if(chmin(rcost.at(make_pair(x, rgraph.at(p.second).at(i).to)), rcost.at(make_pair(x, p.second))+rgraph.at(p.second).at(i).time)){
          q.push(make_pair(rcost.at(make_pair(x, rgraph.at(p.second).at(i).to)), rgraph.at(p.second).at(i).to));
        }
      }
      else{
        rcost[make_pair(x, rgraph.at(p.second).at(i).to)] = rcost.at(make_pair(x, p.second))+rgraph.at(p.second).at(i).time;
        q.push(make_pair(rcost.at(make_pair(x, rgraph.at(p.second).at(i).to)), rgraph.at(p.second).at(i).to));
      }
    }
  }
}

int main(){
  ll N, M, T;
  cin >> N >> M >> T;
  graph.resize(N);
  rgraph.resize(N);
  rep(i, N){
    cost[make_pair(i, i)] = 0;
    rcost[make_pair(i, i)] = 0;
  }
  vector<ll> A(N);
  rep(i, N){
    cin >> A.at(i);
  }
  rep(i, M){
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    graph.at(a).push_back({b, c});
    rgraph.at(b).push_back({a, c});
  }
  dijkstra(0);
  rdijkstra(0);
  ll ans = 0;
  //留まる頂点は1つでよいので、最適な頂点を探す
  rep(i, N){
    if(cost.count(make_pair(0, i)) && rcost.count(make_pair(0, i))){
        chmax(ans, A.at(i) * (T - cost.at(make_pair(0, i)) - rcost.at(make_pair(0, i))));
    }
  }
  cout << ans << endl;
}