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

vector<ll> L(200000, INF), R(200000, -1);

ll leaf = 1;

void dfs(ll x, ll p = -1){
    if(sz(graph.at(x)) == 1 && p != -1){
        L.at(x) = leaf;
        R.at(x) = leaf;
        leaf++;
    }
    for(edge e : graph.at(x)){
        if(e.to == p){
            continue;
        }
        dfs(e.to, x);
        chmin(L.at(x), L.at(e.to));
        chmax(R.at(x), R.at(e.to));
    }
}

int main()
{
    ll N;
    cin >> N;
    graph.resize(N);
    rep(i, N-1){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        graph.at(u).push_back({v});
        graph.at(v).push_back({u});
    }
    dfs(0);
    rep(i, N){
        cout << L.at(i) << " " << R.at(i) << endl;
    }
}