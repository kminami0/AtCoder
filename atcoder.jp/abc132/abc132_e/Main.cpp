#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
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
};
vector<vector<edge>> graph;
vector<ll> dist(300000, -1);

queue<pair<ll, ll>> q;

void bfs(ll x, ll d){
    if(dist.at(x) >= 0){
      return;
    }
    dist.at(x) = d;
    q.push({x, d});
}

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(3*N);
    rep(i, M){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        graph.at(u).push_back({N+v});
        graph.at(N+u).push_back({2*N+v});
        graph.at(2*N+u).push_back({v});
    }
    ll S, T;
    cin >> S >> T;
    S--;
    T--;
    q.push({S, 0});
    dist.at(S) = 0;
    while(!q.empty()){
        pair<ll, ll> p = q.front();
        q.pop();
        for(auto e : graph.at(p.first)){
          bfs(e.to, p.second+1);
        }
    }
    if(dist.at(T) != -1){
        cout << dist.at(T)/3 << endl;
    }
    else{
        cout << -1 << endl;
    }
}