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
template <typename T>
bool chmin2(T &a, const T& b) {
  if (a >= b) {
    a = b;
    return true;
  }
  return false;
}

struct edge {
  ll to;
  ll yen;
  ll snuuk;
};
vector<vector<edge>> graph;

int main()
{
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    graph.resize(n);
    rep(i, m){
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        graph.at(u).push_back({v, a, b});
        graph.at(v).push_back({u, a, b});
    }
    vector<ll> cost_from_s(n, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, s});
    while(!q.empty()){
        pair<ll, ll> p = q.top();
        q.pop();
        if(!chmin2(cost_from_s.at(p.second), p.first)){
            continue;
        }
        for(auto e : graph.at(p.second)){
            ll cost = cost_from_s.at(p.second) + e.yen;
            if(chmin(cost_from_s.at(e.to), cost)){\
                q.push({cost_from_s.at(e.to), e.to});
            }
        }
    }
    vector<ll> cost_from_t(n, INF);
    q.push({0, t});
    while(!q.empty()){
        pair<ll, ll> p = q.top();
        q.pop();
        if(!chmin2(cost_from_t.at(p.second), p.first)){
            continue;
        }
        for(auto e : graph.at(p.second)){
            ll cost = cost_from_t.at(p.second) + e.snuuk;
            if(chmin(cost_from_t.at(e.to), cost)){
                q.push({cost_from_t.at(e.to), e.to});
            }
        }
    }
    vector<ll> ans(n);
    ans.at(n-1) = 1000000000000000 - cost_from_s.at(n-1) - cost_from_t.at(n-1);
    rep(i, n-1){
        ans.at(n-2-i) = max(ans.at(n-1-i), 1000000000000000 - cost_from_s.at(n-2-i) - cost_from_t.at(n-2-i));
    }
    rep(i, n){
        cout << ans.at(i) << endl;
    }
}