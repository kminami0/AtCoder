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
    ll N;
    cin >> N;
    graph.resize(400000);
    init(400000);
    rep(i, N){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).push_back({b});
        graph.at(b).push_back({a});
        unite(a, b);
    }
    map<ll, set<ll>> con_com;
    rep(i, 400000){
      con_com[root(i)].insert(i);
    }
    ll ans = 0;
    for(auto p : con_com){
      ll cnt = 0;
      for(auto q : p.second){
        cnt += sz(graph.at(q));
      }
      cnt /= 2;
      if(cnt == sz(p.second) - 1){
        ans += sz(p.second) - 1;
      }
      else{
        ans += sz(p.second);
      }
    }
    cout << ans << endl;
}