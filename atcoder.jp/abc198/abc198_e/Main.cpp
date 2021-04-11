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
vector<bool> p(100000, false);
vector<ll> C(100000);
set<ll> used;
set<ll> uni;

void dfs(ll x){
    if(p.at(x)){
        return;
    }
    p.at(x) = true;
    if(!used.count(C.at(x))){
        uni.insert(x);
        used.insert(C.at(x));
    }
    for(auto e : graph.at(x)){
        dfs(e.to);
    }
    if(uni.count(x)){
        used.erase(C.at(x));
    }
}

int main()
{
    ll N;
    cin >> N;
    graph.resize(N);
    rep(i, N) cin >> C.at(i);
    vector<ll> A(N-1), B(N-1);
    rep(i, N-1){
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
        graph.at(A.at(i)).push_back({B.at(i)});
        graph.at(B.at(i)).push_back({A.at(i)});
    }
    dfs(0);
    for(auto x : uni){
        cout << x+1 << '\n';
    }
}