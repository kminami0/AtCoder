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

struct edge{
    ll to;
    ll score;
};

vector<vector<edge>> tree;
vector<ll> d;
priority_queue<ll> q;

void dfs(ll x, ll p){
    ll y = q.top();
    q.pop();
    d.at(x) = y;
    for(auto e : tree.at(x)){
        if(e.to == p){
            continue;
        }
        dfs(e.to, x);
    }
}

int main()
{
    ll N;
    cin >> N;
    tree.resize(N);
    d.resize(N);
    rep(i, N-1){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        tree.at(a).push_back({b, INF});
        tree.at(b).push_back({a, INF});
    }
    vector<ll> c(N);
    rep(i, N) cin >> c.at(i);
    vector<pair<ll, ll>> deg(N);
    rep(i, N){
        deg.at(i) = make_pair(sz(tree.at(i)), i);
    }
    sort(all(deg));
    rep(i, N){
        q.push(c.at(i));
    }
    dfs(0, -1);
    ll M = 0;
    rep(i, N){
        for(auto e : tree.at(i)){
            ll x = min(d.at(i), d.at(e.to));
            chmin(e.score, x);
            M += e.score;
        }
    }
    cout << M / 2 << endl;
    rep(i, N-1){
        cout << d.at(i) << " ";
    }
    cout << d.at(N-1) << endl;
}