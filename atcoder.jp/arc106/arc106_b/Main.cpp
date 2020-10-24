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
    vector<ll> a(N);
    rep(i, N) cin >> a.at(i);
    vector<ll> b(N);
    rep(i, N) cin >> b.at(i);
    rep(i, M){
        ll c, d;
        cin >> c >> d;
        c--;
        d--;
        graph.at(c).push_back({d});
        graph.at(d).push_back({c});
        unite(c, d);
    }
    map<ll, ll> s;
    map<ll, ll> g;
    rep(i, N){
        s[root(i)] += a.at(i);
        g[root(i)] += b.at(i);
    }
    rep(i, N){
        if(s.at(root(i)) != g.at(root(i))){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}