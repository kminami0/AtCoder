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
  ll cost;
};
vector<vector<edge>> graph;

vector<ll> ds(1000, INF);
vector<ll> dt(1000, INF);
priority_queue<ll, vector<ll>, greater<ll>> q;

int main()
{
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    graph.resize(n);
    rep(i, m){
        ll x, y, d;
        cin >> x >> y >> d;
        x--;
        y--;
        graph.at(x).push_back({y, d});
        graph.at(y).push_back({x, d});
    }
    ds.at(s) = 0;
    q.push(s);
    while(!q.empty()){
        ll p = q.top();
        q.pop();
        for(auto e : graph.at(p)){
            if(chmin(ds.at(e.to), ds.at(p)+e.cost)){
                q.push(e.to);
            }
        }
    }
    dt.at(t) = 0;
    q.push(t);
    while(!q.empty()){
        ll p = q.top();
        q.pop();
        for(auto e : graph.at(p)){
            if(chmin(dt.at(e.to), dt.at(p)+e.cost)){
                q.push(e.to);
            }
        }
    }
    rep(i, n){
        if(ds.at(i) == dt.at(i) && ds.at(i) != INF){
            cout << i+1 << endl;
            return 0;
        }
        if(i == n-1){
            cout << -1 << endl;
            return 0;
        }
    }
}