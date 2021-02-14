#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
#define EPSILON 0.00000000000001 // 10^-14
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

vector<ll> dp1(100000,-1);
vector<bool> dp2(100000,false);
//dp1.at(i)はiを根とする部分木でゲームをしたとき後手が獲得するコインの数-先手が獲得するコインの数
//dp2.at(i)はiを根とする部分木でゲームをしたとき先手がゲームを終えるならtrue

set<ll> leaf;

void dfs(ll v, ll p = -1){
    if(leaf.count(v)){
        return;
    }
    vector<ll> gr1(0), gr2(0), gr3(0);
    for(auto e : graph.at(v)){
        if(e.to == p){
            continue;
        }
        dfs(e.to, v);
        if(dp2.at(e.to)){
            if(dp1.at(e.to) >= 0){
                gr1.push_back(dp1.at(e.to));
            }
            else{
                gr2.push_back(dp1.at(e.to));
            }
        }
        else{
            gr3.push_back(dp1.at(e.to));
        }
    }
    sort(rbegin(gr3), rend(gr3));
    for(auto p : gr1){
        dp1.at(v) += p;
    }
    ll s = 1;
    rep(i, sz(gr3)){
        dp1.at(v) += gr3.at(i) * s;
        s *= -1;
    }
    for(auto p : gr2){
        dp1.at(v) += p * s;
    }
    if(s == -1){
        dp2.at(v) = true;
    }
}

//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll n;
    cin >> n;
    graph.resize(n);
    vector<ll> p(n);
    p.at(0) = -1;
    rep(i, n){
        leaf.insert(i);
    }
    rep2(i, 1, n){
        cin >> p.at(i);
        p.at(i)--;
        graph.at(i).push_back({p.at(i)});
        graph.at(p.at(i)).push_back({i});
        if(leaf.count(p.at(i))){
            leaf.erase(p.at(i));
        }
    }
    dfs(0);
    cout << (-dp1.at(0) + n) / 2 << '\n';
}