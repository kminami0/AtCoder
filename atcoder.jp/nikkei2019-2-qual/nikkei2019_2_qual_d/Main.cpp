#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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
    vector<ll> imos(N, 0);
    rep(i, M){
        ll L, R, C;
        cin >> L >> R >> C;
        L--;
        R--;
        graph.at(L).push_back({R, C});
        imos.at(L)++;
        imos.at(R)--;
    }
    rep(i, N-1){
        imos.at(i+1) += imos.at(i);
    }
    rep(i, N-1){
        if(imos.at(i) > 0){
            graph.at(i+1).push_back({i, 0});
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
    if(cost.at(N-1) == INF){
        cout << -1 << endl;
    }
    else{
        cout << cost.at(N-1) << endl;
    }
}