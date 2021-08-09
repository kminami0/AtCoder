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
  ll cost;
};
vector<vector<edge>> graph;

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i, H){
        cin >> S.at(i);
    }
    graph.resize(H*W);
    rep(i, H){
        rep(j, W){
            if(S.at(i).at(j) == '#'){
                if(j != W-1){
                    if(S.at(i).at(j+1) == '.'){
                        graph.at(i*W+j).push_back({i*W+j+1, 0});
                    }
                }
                if(i != H-1){
                    if(S.at(i+1).at(j) == '.'){
                        graph.at(i*W+j).push_back({(i+1)*W+j, 0});
                    }
                }
            }
            else{
                if(j != W-1){
                    if(S.at(i).at(j+1) == '.'){
                        graph.at(i*W+j).push_back({i*W+j+1, 0});
                        graph.at(i*W+j+1).push_back({i*W+j, 0});
                    }
                }
                if(i != H-1){
                    if(S.at(i+1).at(j) == '.'){
                        graph.at(i*W+j).push_back({(i+1)*W+j, 0});
                        graph.at((i+1)*W+j).push_back({i*W+j, 0});
                    }
                }
            }
        }
    }
    rep(i, H){
        rep(j, W){
            rep2(k, i-2, i+3){
                rep2(l, j-2, j+3){
                    if(k < 0 || k >= H || l < 0 || l >= W){
                        continue;
                    }
                    if((k == i-2 && l == j-2) || (k == i-2 && l == j+2) || (k == i+2 && l == j-2) || (k == i+2 && l == j+2)){
                        continue;
                    }
                    graph.at(i*W+j).push_back({k*W+l, 1});
                }
            }
        }
    }
    vector<ll> cost(H*W, INF);
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
            ll d = cost.at(p.second) + e.cost;
            if(chmin(cost.at(e.to), d)){
                q.push({cost.at(e.to), e.to});
            }
        }
    }
    cout << cost.at(H*W-1) << '\n';
}