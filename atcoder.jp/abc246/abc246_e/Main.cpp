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
  ll dist;
};
vector<vector<edge>> graph;

int main()
{
    ll N, Ax, Ay, Bx, By;
    cin >> N >> Ax >> Ay >> Bx >> By;
    Ax--;
    Ay--;
    Bx--;
    By--;
    vector<string> S(N);
    rep(i, N){
        cin >> S.at(i);
    }
    if((Ax+Ay) % 2 != (Bx+By) % 2){
        cout << -1 << '\n';
        return 0;
    }
    graph.resize(N*N*2);
    // \方向は0 /方向は1
    rep(i, N-1){
        rep(j, N){
            if(S.at(i).at(j) == '#'){
                continue;
            }
            if(j >= 1 && S.at(i+1).at(j-1) == '.'){
                graph.at(N*i+j + N*N).push_back({N*(i+1)+(j-1) + N*N, 0});
                graph.at(N*(i+1)+(j-1) + N*N).push_back({N*i+j + N*N, 0});
            }
            if(j <= N-2 && S.at(i+1).at(j+1) == '.'){
                graph.at(N*i+j).push_back({N*(i+1)+(j+1), 0});
                graph.at(N*(i+1)+(j+1)).push_back({N*i+j, 0});
            }
            graph.at(N*i+j).push_back({N*i+j + N*N, 1});
            graph.at(N*i+j + N*N).push_back({N*i+j, 1});
        }
    }
    vector<ll> cost(N*N*2, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, N*Ax+Ay});
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
    ll ans = INF;
    chmin(ans, cost.at(N*Bx+By));
    chmin(ans, cost.at(N*Bx+By + N*N));
    rep(i, N*N*2){
        cost.at(i) = INF;
    }
    q.push({0, N*Ax+Ay + N*N});
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
    chmin(ans, cost.at(N*Bx+By));
    chmin(ans, cost.at(N*Bx+By + N*N));
    if(ans == INF){
        cout << -1 << '\n';
    }
    else{
        cout << ans+1 << '\n';
    }
}