#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
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

deque<pair<ll, ll>> q;
vector<ll> dist(4010000, -1);

void bfs(ll x, ll y, bool tlp){
    if(dist.at(x) != -1){
        return;
    }
    if(tlp){
        dist.at(x) = y;
        q.push_front({x, y});
    }
    else{
        dist.at(x) = y + 1;
        q.push_back({x, y+1});
    }
}

int main()
{
    ll H, W;
    cin >> H >> W;
    graph.resize((H+2)*(W+2)+26); //テレポーターa~zはそれぞれ(H+2)*(W+2) ~ (H+2)*(W+2)+25を経由してテレポートするとする
    //入力の周囲を壁で覆う
    vector<string> a(H+2, "");
    rep(i, W+2){
        a.at(0) += "#";
        a.at(H+1) += "#";
    }
    rep(i, H){
        cin >> a.at(i+1);
        a.at(i+1) = "#" + a.at(i+1) + "#";
    }
    ll start = 0;
    ll goal = 0;
    rep(i, H+2){
        rep(j, W+2){
            if(a.at(i).at(j) == 'S'){
                start = i*(W+2)+j;
            }
            if(a.at(i).at(j) == 'G'){
                goal = i*(W+2)+j;
            }
        }
    }
    rep(i, H+2){
        rep(j, W+2){
            if(a.at(i).at(j) == '#'){
                continue;
            }
            if(a.at(i-1).at(j) != '#'){
                graph.at(i*(W+2)+j).push_back({(i-1)*(W+2)+j});
            }
            if(a.at(i+1).at(j) != '#'){
                graph.at(i*(W+2)+j).push_back({(i+1)*(W+2)+j});
            }
            if(a.at(i).at(j-1) != '#'){
                graph.at(i*(W+2)+j).push_back({i*(W+2)+j-1});
            }
            if(a.at(i).at(j+1) != '#'){
                graph.at(i*(W+2)+j).push_back({i*(W+2)+j+1});
            }
            if(islower(a.at(i).at(j))){
                graph.at(i*(W+2)+j).push_back({(H+2)*(W+2)+a.at(i).at(j)-'a'});
                graph.at((H+2)*(W+2)+a.at(i).at(j)-'a').push_back({i*(W+2)+j});
            }
        }
    }
    q.push_front({start, 0});
    while(!q.empty()){ //01BFSで最短時間を求める。テレポーターから経由地へは0秒、経由地からテレポーターへは1秒で移動できるとする
        pair<ll, ll> p = q.front();
        q.pop_front();
        bool tlp = false;
        ll i = p.first / (W+2);
        ll j = p.first % (W+2);
        for(auto e : graph.at(p.first)){
            if(e.to >= (H+2)*(W+2)){
                tlp = true;
            }
            bfs(e.to, p.second, tlp);
        }
    }
    cout << dist.at(goal) << endl;
}