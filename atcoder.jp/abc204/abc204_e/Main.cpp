#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
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
  ll C;
  ll D;
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

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    init(N);
    rep(i, M){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        graph.at(a).push_back({b, c, d});
        graph.at(b).push_back({a, c, d});
        unite(a, b);
    }
    if(!same(0, N-1)){
        cout << -1 << '\n';
        return 0;
    }
    vector<ll> cost(N, INF);
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
            ll d;
            if(cost.at(p.second) <= ll(round(sqrt(e.D))-1)){
                d = ll(round(sqrt(e.D)))-1 + e.C + e.D/ll(round(sqrt(e.D)));
            }
            else{
                d = cost.at(p.second) + e.C + e.D/(cost.at(p.second)+1);
            }
            if(chmin(cost.at(e.to), d)){
                q.push({cost.at(e.to), e.to});
            }
        }
    }
    cout << cost.at(N-1) << '\n';
}