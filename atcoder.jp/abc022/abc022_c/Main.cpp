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
  ll dist;
};
vector<vector<edge>> graph;

vector<ll> par(1000000);
vector<ll> rnk(1000000);

void init(ll n){
  rep(i, n){
    par.at(i) = i;
    rnk.at(i) = 0;
  }
}

ll root(ll x){
  if(par.at(x) == x){
    return x;
  }
  else{
    par.at(x) = root(par.at(x));
    return par.at(x);
  }
}

bool same(ll x, ll y){
  if(root(x) == root(y)){
    return true;
  }
  else{
    return false;
  }
}

void unite(ll x, ll y){
  x = root(x);
  y = root(y);
  if(x == y){
    return;
  }
  if(rnk.at(x) < rnk.at(y)){
    par.at(x) = y;
  }
  else{
    par.at(y) = x;
    if(rnk.at(x) == rnk.at(y)){
      rnk.at(x)++;
    }
  }
}

priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    init(N);
    rep(i, M){
        ll u, v, l;
        cin >> u >> v >> l;
        u--;
        v--;
        graph.at(u).push_back({v, l});
        graph.at(v).push_back({u, l});
        unite(u, v);
    }
    ll ans = INF;
    // 以下で家1を含む最短閉路長を求める
    // 家1と隣接する家をつなぐ道を削除し、その隣接する家から家1までの
    // 最短経路長と元々つないでいた道の長さの和が閉路長になる
    // 家1から出る各道に対しこの操作を行う
    for(auto e : graph.at(0)){
        vector<vector<ll>> d(N, vector<ll>(N, INF));
        // d.at(i).at(j)で家i+iから家j+1への最短距離を表す
        rep(i, N){
            d.at(i).at(i) = 0;
        }
        q.push({0, e.to});
        while(!q.empty()){
            pair<ll, ll> p = q.top();
            q.pop();
            if(d.at(e.to).at(p.second) < p.first){
                continue;
            }
            for(auto f : graph.at(p.second)){
                if(p.second == e.to && f.to == 0){
                    continue;
                }
                if(chmin(d.at(e.to).at(f.to), d.at(e.to).at(p.second) + f.dist)){
                    q.push({d.at(e.to).at(f.to), f.to});
                }
            }
        }
        chmin(ans, e.dist + d.at(e.to).at(0));
    }
    if(ans == INF){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
}