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
    ll N;
    cin >> N;
    graph.resize(N);
    queue<ll> manu;
    rep(i, N){
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        graph.at(A).push_back({i});
        graph.at(B).push_back({i});
        if(A == i || B == i){
            manu.push(i);
        }
    }
    vector<ll> X(0);
    set<ll> used;
    while(!manu.empty()){
        ll p = manu.front();
        manu.pop();
        if(used.count(p)){
            continue;
        }
        used.insert(p);
        for(edge e : graph.at(p)){
            if(!used.count(e.to)){
                manu.push(e.to);
            }
        }
        X.push_back(p+1);
    }
    if(ll(sz(X)) == N){
        reverse(all(X));
        for(ll x : X){
            cout << x << '\n';
        }
    }
    else{
        cout << -1 << '\n';
    }
}