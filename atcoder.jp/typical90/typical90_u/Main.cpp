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
};
vector<vector<edge>> graph;
vector<vector<edge>> rgraph;

vector<bool> vst(100000, false);
vector<ll> t(0);

void bfs(ll x){
    if(vst.at(x)){
        return;
    }
    vst.at(x) = true;
    for(edge e : graph.at(x)){
        bfs(e.to);
    }
    t.push_back(x);
}

ll p = 0;
vector<ll> cn(100000);

void scc(ll x){
    if(vst.at(x)){
        return;
    }
    vst.at(x) = true;
    cn.at(x) = p;
    for(edge e : rgraph.at(x)){
        scc(e.to);
    }
}

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    rgraph.resize(N);
    rep(i, M){
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        graph.at(A).push_back({B});
        rgraph.at(B).push_back({A});
    }
    rep(i, N){
        bfs(i);
    }
    rep(i, N){
        vst.at(i) = false;
    }
    reverse(all(t));
    rep(i, N){
        scc(t.at(i));
        p++;
    }
    vector<ll> comp(N);
    rep(i, N){
        comp.at(cn.at(i))++;
    }
    ll ans = 0;
    rep(i, N){
        ans += comp.at(i) * (comp.at(i) - 1) / 2;
    }
    cout << ans << '\n';
}