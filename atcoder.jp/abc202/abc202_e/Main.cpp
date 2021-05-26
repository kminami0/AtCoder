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

vector<bool> vst(200000, false);
vector<ll> in(200000, -1);
vector<ll> out(200000, -1);

ll c = 0;
ll d = 0;
vector<vector<ll>> depth(200000, vector<ll>(0));
ll lastin = 0;

void dfs(ll x){
    if(vst.at(x)){
        d--;
        return;
    }
    vst.at(x) = true;
    in.at(x) = c;
    lastin = c;
    depth.at(d).push_back(c);
    c++;
    for(edge e : graph.at(x)){
        d++;
        dfs(e.to);
    }
    out.at(x) = lastin;
    d--;
}

int main()
{
    ll N;
    cin >> N;
    graph.resize(N);
    rep(i, N-1){
        ll x;
        cin >> x;
        x--;
        graph.at(i+1).push_back({x});
        graph.at(x).push_back({i+1});
    }
    dfs(0);
    rep(i, N){
        sort(all(depth.at(i)));
    }
    ll Q;
    cin >> Q;
    rep(i, Q){
        ll U, D;
        cin >> U >> D;
        U--;
        ll le = in.at(U);
        ll re = out.at(U);
        auto iterl = lower_bound(all(depth.at(D)), le);
        auto iterr = upper_bound(all(depth.at(D)), re);
        cout << iterr - iterl << '\n';
    }
}