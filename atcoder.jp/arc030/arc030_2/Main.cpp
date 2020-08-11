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
vector<pair<vector<edge>, ll>> graph;

vector<bool> vst(100, false);

ll ans = 0;

bool dfs(ll p, ll q){
    if(vst.at(q)){
        return false;
    }
    vst.at(q) = true;
    bool j = false;
    if(graph.at(q).second == 1){
        j = true;
    }
    for(auto e : graph.at(q).first){
        if(e.to == p){
            continue;
        }
        j = dfs(q, e.to) || j;
    }
    if(j && p != -1){
        ans += 2;
    }
    return j;
}

int main()
{
    ll n, x;
    cin >> n >> x;
    x--;
    graph.resize(n);
    rep(i, n){
        ll h;
        cin >> h;
        graph.at(i).second = h;
    }
    rep(i, n-1){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).first.push_back({b});
        graph.at(b).first.push_back({a});
    }
    dfs(-1, x);
    cout << ans << endl;
}