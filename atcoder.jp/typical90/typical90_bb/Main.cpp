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
};
vector<vector<edge>> graph;

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N+M);
    rep(i, M){
        ll K;
        cin >> K;
        rep(j, K){
            ll R;
            cin >> R;
            R--;
            graph.at(N+i).push_back({R});
            graph.at(R).push_back({N+i});
        }
    }
    vector<ll> cost(N+M, INF);
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
            ll d = cost.at(p.second) + 1;
            if(chmin(cost.at(e.to), d)){
                q.push({cost.at(e.to), e.to});
            }
        }
    }
    rep(i, N){
        if(cost.at(i) < INF){
            cout << cost.at(i)/2 << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
}