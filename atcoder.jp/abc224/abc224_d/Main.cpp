#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
#define INF 1e18+999999
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
};
vector<vector<edge>> graph;

map<pair<vector<ll>, ll>, ll> dist;

int main()
{
    graph.resize(9);
    ll M;
    cin >> M;
    rep(i, M){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        graph.at(u).push_back({v});
        graph.at(v).push_back({u});
    }
    vector<ll> p(8);
    set<ll> S;
    rep(i, 8){
        cin >> p.at(i);
        p.at(i)--;
        S.insert(p.at(i));
    }
    ll v;
    rep(i, 9){
        if(!S.count(i)){
            v = i;
            break;
        }
    }
    queue<tuple<vector<ll>, ll, ll>> q;
    q.push({p, v, 0});
    while(!q.empty()){
        tuple<vector<ll>, ll, ll> state = q.front();
        q.pop();
        if(dist.count({get<0>(state), get<1>(state)})){
            continue;
        }
        ll d = get<2>(state);
        dist[{get<0>(state), get<1>(state)}] = d;
        ll vv = get<1>(state);
        for(edge e : graph.at(vv)){
            vector<ll> p2 = get<0>(state);
            ll v2;
            rep(i, 8){
                if(p2.at(i) == e.to){
                    p2.at(i) = vv;
                    v2 = e.to;
                    break;
                }
            }
            q.push({p2, v2, d+1});
        }
    }
    if(!dist.count({{0,1,2,3,4,5,6,7}, 8})){
        cout << -1 << '\n';
    }
    else{
        cout << dist.at({{0,1,2,3,4,5,6,7}, 8}) << '\n';
    }
}