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
};
vector<vector<edge>> graph;

int main()
{
    ll H, W, sx, sy, gx, gy;
    cin >> H >> W >> sx >> sy >> gx >> gy;
    sx--;
    sy--;
    gx--;
    gy--;
    vector<string> S(H);
    rep(i, H){
      cin >> S.at(i);
    }
    graph.resize(H*W*2); //H*W未満は上下、H*W以上は左右で入る
    rep(i, H){
      rep(j, W){
        if(i != 0 && S.at(i-1).at(j) == '.'){
          graph.at(i*W+j+H*W).push_back({(i-1)*W+j});
        }
        if(i != H-1 && S.at(i+1).at(j) == '.'){
          graph.at(i*W+j+H*W).push_back({(i+1)*W+j});
        }
        if(j != 0 && S.at(i).at(j-1) == '.'){
          graph.at(i*W+j).push_back({i*W+j-1+H*W});
        }
        if(j != W-1 && S.at(i).at(j+1) == '.'){
          graph.at(i*W+j).push_back({i*W+j+1+H*W});
        }
      }
    }
    queue<pair<ll, ll>> q;
    q.push({sx*W+sy, 0});
    vector<ll> d1(2*H*W, -1);
    d1.at(sx*W+sy) = 0;
    while(!q.empty()){
      pair<ll, ll> p = q.front();
      q.pop();
      for(auto e : graph.at(p.first)){
        if(d1.at(e.to) != -1){
          continue;
        }
        d1.at(e.to) = p.second+1;
        q.push({e.to, p.second+1});
      }
    }
    q.push({sx*W+sy+H*W, 0});
    vector<ll> d2(2*H*W, -1);
    d2.at(sx*W+sy+H*W) = 0;
    while(!q.empty()){
      pair<ll, ll> p = q.front();
      q.pop();
      for(auto e : graph.at(p.first)){
        if(d2.at(e.to) != -1){
          continue;
        }
        d2.at(e.to) = p.second+1;
        q.push({e.to, p.second+1});
      }
    }
    ll ans = INF;
    if(d1.at(gx*W+gy) != -1){
      chmin(ans, d1.at(gx*W+gy));
    }
    if(d1.at(gx*W+gy+H*W) != -1){
      chmin(ans, d1.at(gx*W+gy+H*W));
    }
    if(d2.at(gx*W+gy) != -1){
      chmin(ans, d2.at(gx*W+gy));
    }
    if(d2.at(gx*W+gy+H*W) != -1){
      chmin(ans, d2.at(gx*W+gy+H*W));
    }
    if(ans == INF){
      cout << -1 << endl;
    }
    else{
      cout << ans << endl;
    }
}