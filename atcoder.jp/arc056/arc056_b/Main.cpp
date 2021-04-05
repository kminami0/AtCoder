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
};
vector<vector<edge>> graph;

int main()
{
    ll N, M, S;
    cin >> N >> M >> S;
    S--;
    graph.resize(N);
    rep(i, M){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        graph.at(u).push_back({v});
        graph.at(v).push_back({u});
    }
    vector<ll> cost(N, -1);
    //頂点iへはcost.at(i)以上の頂点だけを通ってたどり着け、cost.at(i)+1以上の頂点だけを通ってたどり着くことはできない
    priority_queue<pair<ll, ll>> q;
    q.push({S, S});
    while(!q.empty()){
        pair<ll, ll> p = q.top();
        q.pop();
        chmax(cost.at(p.second), p.first);
        for(auto e : graph.at(p.second)){
            ll d = min(cost.at(p.second), e.to);
            if(chmax(cost.at(e.to), d)){
                q.push({cost.at(e.to), e.to});
            }
        }
    }
    rep(i, N){
        if(cost.at(i) >= i){
            cout << i+1 << '\n';
        }
    }
}