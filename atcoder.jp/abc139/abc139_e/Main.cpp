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
vector<vector<ll>> id(1000, vector<ll>(1000));

ll toId(ll i, ll j){
    if(i > j){
        swap(i, j);
    }
    return id.at(i).at(j);
}

vector<bool> visited;
vector<bool> calculated;
vector<ll> dp;
//dp.at(i)はiからの最長経路長

ll dfs(ll v){
    if(visited.at(v)){
        if(!calculated.at(v)){
            return -1;
        }
        return dp.at(v);
    }
    visited.at(v) = true;
    dp.at(v) = 0;
    for(auto e : graph.at(v)){
        ll res = dfs(e.to);
        if(res == -1){
            return -1;
        }
        chmax(dp.at(v), res+1);
    }
    calculated.at(v) = true;
    return dp.at(v);
}

int main()
{
    ll N;
    cin >> N;
    graph.resize(N*(N-1)/2);
    visited.resize(N*(N-1)/2);
    calculated.resize(N*(N-1)/2);
    dp.resize(N*(N-1)/2);
    vector<vector<ll>> A(N, vector<ll>(N-1));
    rep(i, N){
        rep(j, N-1){
            cin >> A.at(i).at(j);
            A.at(i).at(j)--;
        }
    }
    ll V = 0;
    rep(i, N){
        rep(j, N){
            if(i < j){
                id.at(i).at(j) = V++;
            }
        }
    }
    rep(i, N){
        rep(j, N-1){
            A.at(i).at(j) = toId(i, A.at(i).at(j));
        }
        rep(j, N-2){
            graph.at(A.at(i).at(j+1)).push_back({A.at(i).at(j)});
        }
    }
    ll ans = 0;
    rep(i, N*(N-1)/2){
        ll res = dfs(i);
        if(res == -1){
            cout << -1 << endl;
            return 0;
        }
        chmax(ans, res);
    }
    cout << ans+1 << endl;
}