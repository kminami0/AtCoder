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

struct edge {
  ll to;
  ll label;
};
vector<vector<edge>> graph;

int main()
{
    ll N, M;
    cin >> N >> M;
    init(N);
    graph.resize(N);
    rep(i, M){
        ll u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        //union-findを用いて入力の全域木をとる
        if(!same(u, v)){
            graph.at(u).push_back({v, c});
            graph.at(v).push_back({u, c});
            unite(u, v);
        }
    }
    vector<ll> ans(N, -1);
    ans.at(0) = 1;
    queue<ll> q;
    q.push(0);
    //BFSでよい書き込み方を構成する
    while(!q.empty()){
        ll p = q.front();
        q.pop();
        for(auto e : graph.at(p)){
            if(ans.at(e.to) == -1){
                if(ans.at(p) == e.label){
                    ans.at(e.to) = e.label % N + 1;
                }
                else{
                    ans.at(e.to) = e.label;
                }
                q.push(e.to);
            }
        }
    }
    rep(i, N){
        cout << ans.at(i) << endl;
    }
}