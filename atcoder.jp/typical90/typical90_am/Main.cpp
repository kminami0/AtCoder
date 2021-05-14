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

vector<bool> vst(100000, false);
vector<ll> dp(100000, 0);

void dfs(ll x, ll p = -1){
    if(vst.at(x)){
        return;
    }
    vst.at(x) = true;
    if(sz(graph.at(x)) == 1){
        dp.at(x) = 1;
    }
    ll cnt = 0;
    for(edge e : graph.at(x)){
        if(e.to == p){
            continue;
        }
        dfs(e.to, x);
        cnt += dp.at(e.to);
    }
    dp.at(x) = cnt + 1;
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
        graph.at(a).push_back({b});
        graph.at(b).push_back({a});
    }
    dfs(0);
    ll ans = 0;
    rep(i, N){
        for(edge e : graph.at(i)){
            if(dp.at(i) > dp.at(e.to)){
                ans += dp.at(e.to) * (N - dp.at(e.to));
            }
        }
    }
    cout << ans << '\n';
}