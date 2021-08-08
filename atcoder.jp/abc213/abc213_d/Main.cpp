#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
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


vector<vector<ll>> graph;
vector<bool> vst(200000, false);
vector<ll> tour(0);

void dfs(ll x, ll p = -1){
    if(vst.at(x)){
        return;
    }
    vst.at(x) = true;
    tour.push_back(x);
    for(ll e : graph.at(x)){
        if(e == p){
            continue;
        }
        dfs(e, x);
        tour.push_back(x);
    }
}

int main()
{
    ll N;
    cin >> N;
    graph.resize(N);
    rep(i, N-1){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }
    rep(i, N){
        sort(all(graph.at(i)));
    }
    dfs(0);
    ll L = sz(tour);
    rep(i, L-1){
        cout << tour.at(i)+1 << " ";
    }
    cout << tour.at(L-1)+1 << '\n';
}