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

int main()
{
    string first, last;
    ll N;
    cin >> first >> last >> N;
    if(first == last){
        cout << 0 << endl;
        cout << first << endl;
        cout << last << endl;
        return 0;
    }
    graph.resize(N+2);
    vector<string> s(N);
    rep(i, N){
        cin >> s.at(i);
    }
    s.push_back(first);
    s.push_back(last);
    rep(i, N+2){
        rep2(j, i+1, N+2){
            ll diff = 0;
            rep(k, sz(s.at(i))){
                if(s.at(i).at(k) != s.at(j).at(k)){
                    diff++;
                }
            }
            if(diff == 1){
                graph.at(i).push_back({j});
                graph.at(j).push_back({i});
            }
        }
    }
    queue<pair<ll, vector<ll>>> q;
    q.push({N, {N}});
    vector<vector<ll>> dist(N+2, vector<ll>(0));
    dist.at(N) = {N};
    while(!q.empty()){
        pair<ll, vector<ll>> p = q.front();
        q.pop();
        for(auto e : graph.at(p.first)){
            if(!dist.at(e.to).empty()){
                continue;
            }
            dist.at(e.to) = p.second;
            dist.at(e.to).push_back(e.to);
            q.push({e.to, dist.at(e.to)});
        }
    }
    if(dist.at(N+1).empty()){
        cout << -1 << endl;
    }
    else{
        cout << sz(dist.at(N+1)) - 2 << endl;
        for(auto i : dist.at(N+1)){
            cout << s.at(i) << endl;
        }
    }
}