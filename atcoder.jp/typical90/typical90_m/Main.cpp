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
  ll dist;
};
vector<vector<edge>> graph;

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    rep(i, M){
        ll A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        graph.at(A).push_back({B, C});
        graph.at(B).push_back({A, C});
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
    vector<ll> cost2(N, INF);
    q.push({0, N-1});
    while(!q.empty()){
        pair<ll, ll> p = q.top();
        q.pop();
        if(cost2.at(p.second) < p.first){
            continue;
        }
        else{
            cost2.at(p.second) = p.first;
        }
        for(auto e : graph.at(p.second)){
            ll d = cost2.at(p.second) + e.dist;
            if(chmin(cost2.at(e.to), d)){
                q.push({cost2.at(e.to), e.to});
            }
        }
    }
    rep(i, N){
        cout << cost.at(i) + cost2.at(i) << '\n';
    }
}