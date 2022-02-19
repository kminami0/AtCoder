#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
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

vector<vector<ll>> dp(100000, vector<ll>(20, -1));
vector<ll> X(100000);

void dfs(ll v, ll p = -1){
    if(sz(graph.at(v)) == 1 && p != -1){
        dp.at(v).at(0) = X.at(v);
        return;
    }
    for(edge e : graph.at(v)){
        if(e.to == p){
            continue;
        }
        dfs(e.to, v);
        vector<ll> tmp(40);
        rep(i, 20){
            tmp.at(i) = dp.at(v).at(i);
        }
        rep(i, 20){
            tmp.at(i+20) = dp.at(e.to).at(i);
        }
        sort(all(tmp));
        reverse(all(tmp));
        rep(i, 20){
            dp.at(v).at(i) = tmp.at(i);
        }
    }
    dp.at(v).push_back(X.at(v));
    sort(all(dp.at(v)));
    reverse(all(dp.at(v)));
    dp.at(v).pop_back();
}

int main()
{
    ll N, Q;
    cin >> N >> Q;
    graph.resize(N);
    rep(i, N) cin >> X.at(i);
    rep(i, N-1){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).push_back({b});
        graph.at(b).push_back({a});
    }
    dfs(0);
    rep(i, Q){
        ll V, K;
        cin >> V >> K;
        V--;
        K--;
        cout << dp.at(V).at(K) << '\n';
    }
}