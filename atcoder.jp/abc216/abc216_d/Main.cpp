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

vector<int> topo_sort(vector<vector<edge>> G) {  // bfs
    vector<int> ans;
    int n = (int)G.size();
    vector<int> ind(n);            // ind[i]: 頂点iに入る辺の数(次数)
    for (int i = 0; i < n; i++) {  // 次数を数えておく
        for (auto e : G[i]) {
            ind[e.to]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {  // 次数が0の点をキューに入れる
        if (ind[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {  // 幅優先探索
        int now = que.front();
        ans.push_back(now);
        que.pop();
        for (auto e : G[now]) {
            ind[e.to]--;
            if (ind[e.to] == 0) {
                que.push(e.to);
            }
        }
    }
    return ans;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    vector<ll> k(M);
    vector<vector<ll>> a(M);
    rep(i, M){
        cin >> k.at(i);
        a.at(i).resize(k.at(i));
        rep(j, k.at(i)){
            cin >> a.at(i).at(j);
            a.at(i).at(j)--;
        }
    }
    rep(i, M){
        rep(j, k.at(i)-1){
            graph.at(a.at(i).at(j)).push_back({a.at(i).at(j+1)});
        }
    }
    vector<int> topo = topo_sort(graph);
    if((ll)(sz(topo)) == N){
        cout << "Yes" << '\n';
    }
    else{
        cout << "No" << '\n';
    }
}