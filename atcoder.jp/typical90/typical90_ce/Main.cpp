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

struct edge {
  ll to;
};
vector<vector<edge>> graph;

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    set<pair<ll, ll>> edges;
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).push_back({b});
        graph.at(b).push_back({a});
        edges.insert({a, b});
        edges.insert({b, a});
    }
    ll Q;
    cin >> Q;
    vector<ll> color(N, 1);
    vector<ll> r(N, -1);
    vector<ll> y(Q);
    set<ll> star;
    rep(i, N){
        if(sz(graph.at(i)) * Q >= 3e8){
            star.insert(i);
        }
    }
    rep(i, Q){
        ll x;
        cin >> x >> y.at(i);
        x--;
        if(star.count(x)){
            cout << color.at(x) << '\n';
        }
        else{
            ll tmp = r.at(x);
            ll v = x;
            for(edge e : graph.at(x)){
                if(chmax(tmp, r.at(e.to))){
                    v = e.to;
                }
            }
            if(tmp == -1){
                cout << 1 << '\n';
            }
            else{
                cout << y.at(tmp) << '\n';
            }
        }
        r.at(x) = i;
        color.at(x) = y.at(i);
        for(ll z : star){
            if(edges.count({x, z})){
                color.at(z) = y.at(i);
            }
        }
    }
}