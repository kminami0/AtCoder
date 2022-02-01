#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
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
  ll dist;
};
vector<vector<edge>> graph;

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    vector<ll> H(N);
    rep(i, N) cin >> H.at(i);
    rep(i, M){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        if(H.at(u) > H.at(v)){
            graph.at(u).push_back({v, 0});
            graph.at(v).push_back({u, H.at(u)-H.at(v)});
        }
        else{
            graph.at(v).push_back({u, 0});
            graph.at(u).push_back({v, H.at(v)-H.at(u)});
        }
    }
    vector<ll> cost(N, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 0});
    while(!q.empty()){
        pair<ll, ll> p = q.top();
        q.pop();
        if(cost.at(p.second) < p.first){
            continue;
        }
        else{
            cost.at(p.second) = p.first;
        }
        for(auto e : graph.at(p.second)){
            ll d = cost.at(p.second) + e.dist;
            if(chmin(cost.at(e.to), d)){
                q.push({cost.at(e.to), e.to});
            }
        }
    }
    ll ans = 0;
    rep(i, N){
        chmax(ans, H.at(0) - H.at(i) - cost.at(i));
    }
    cout << ans << '\n';
}