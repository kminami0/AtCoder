#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e9+9
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
  int to;
  int dist;
};
vector<vector<edge>> graph;

int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> A(R, vector<int>(C-1));
    vector<vector<int>> B(R-1, vector<int>(C));
    rep(i, R){
        rep(j, C-1){
            cin >> A[i][j];
        }
    }
    rep(i, R-1){
        rep(j, C){
            cin >> B[i][j];
        }
    }
    graph.resize(R*C);
    rep(i, R){
        rep(j, C-1){
            graph[i*C+j].push_back({i*C+j+1, A[i][j]});
        }
    }
    rep(i, R){
        rep2(j, 1, C){
            graph[i*C+j].push_back({i*C+j-1, A[i].at(j-1)});
        }
    }
    rep(i, R-1){
        rep(j, C){
            graph[i*C+j].push_back({(i+1)*C+j, B[i][j]});
        }
    }
    rep(i, R){
        rep(j, C){
            rep2(k, 1, i+1){
                graph[i*C+j].push_back({(i-k)*C+j, 1+k});
            }
        }
    }
    vector<int> cost(R*C, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});
    while(!q.empty()){
        pair<int, int> p = q.top();
        q.pop();
        if(cost[p.second] < p.first){
            continue;
        }
        else{
            cost[p.second] = p.first;
        }
        for(auto e : graph[p.second]){
            int d = cost[p.second] + e.dist;
            if(chmin(cost[e.to], d)){
                q.push({cost[e.to], e.to});
            }
        }
    }
    cout << cost[R*C-1] << '\n';
}