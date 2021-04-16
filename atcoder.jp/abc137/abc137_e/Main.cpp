#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
#define EPSILON 1e-14
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

struct edge {
  ll to;
  ll cost;
};
vector<vector<edge>> graph;

set<ll> ng;

//https://dai1741.github.io/maximum-algo-2012/docs/shortest-path/
vector<ll> dist; // 最短距離
// 戻り値がtrueなら負の閉路を含む
bool bellman_ford(ll n, ll s) { // nは頂点数、sは開始頂点
  dist = vector<ll>(n, INF);
  dist.at(s) = 0; // 開始点の距離は0
  for (ll i = 0; i < n; i++) {
    for (ll v = 0; v < n; v++) {
      if(ng.count(v)){
        continue;
      }
      for (ll k = 0; k < (ll)graph.at(v).size(); k++) {
        edge e = graph.at(v).at(k);
        if(ng.count(e.to)){
          continue;
        }
        if (dist.at(v) != INF && dist.at(e.to) > dist.at(v) + e.cost) {
          dist.at(e.to) = dist.at(v) + e.cost;
          if (i == n - 1) return true; // n回目にも更新があるなら負の閉路が存在
        }
      }
    }
  }
  return false;
}

vector<vector<edge>> rgraph;

int main()
{
    ll N, M, P;
    cin >> N >> M >> P;
    graph.resize(N);
    rgraph.resize(N);
    rep(i, M){
        ll A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        graph.at(A).push_back({B, -C+P});
        rgraph.at(B).push_back({A, 1});
    }
    vector<ll> cost(N, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, N-1});
    while(!q.empty()){
        pair<ll, ll> p = q.top();
        q.pop();
        if(cost.at(p.second) < p.first){
            continue;
        }
        else{
            cost.at(p.second) = p.first;
        }
        for(auto e : rgraph.at(p.second)){
            ll d = cost.at(p.second) + 1;
            if(chmin(cost.at(e.to), d)){
                q.push({cost.at(e.to), e.to});
            }
        }
    }
    rep(i, N){
        if(cost.at(i) == INF){
            ng.insert(i);
        }
    }
    if(bellman_ford(N, 0)){
        cout << -1 << '\n';
    }
    else{
        cout << max(0LL, -dist.at(N-1)) << '\n';
    }
}