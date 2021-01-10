#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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

vector<ll> gold(200000, -1); // gold.at(i)は町iから到達可能なi以外の町で最も高い金の値段
vector<ll> A(200000);
vector<ll> gold2(200000, -1); // gold.at(i)は町iから到達可能な町で最も高い金の値段

ll bfs(ll x){
    if(gold2.at(x) != -1){
        return gold2.at(x);
    }
    ll M = A.at(x);
    ll L = -INF;
    bool upd = false;
    for(auto e : graph.at(x)){
        ll K = bfs(e.to);
        if(K >= M){
            upd = true;
            M = K;
        }
        chmax(L, K);
    }
    if(upd){
        gold.at(x) = M;
    }
    else{
        gold.at(x) = L;
    }
    gold2.at(x) = M;
    return M;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> X(M), Y(M);
    rep(i, M){
        cin >> X.at(i) >> Y.at(i);
        X.at(i)--;
        Y.at(i)--;
        graph.at(X.at(i)).push_back({Y.at(i)});
    }
    rep(i, N){
        if(gold.at(i) != -1){
            continue;
        }
        bfs(i);
    }
    ll ans = -INF;
    rep(i, N){
        chmax(ans, gold.at(i) - A.at(i));
    }
    cout << ans << endl;
}