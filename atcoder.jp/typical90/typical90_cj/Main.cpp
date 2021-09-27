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

vector<set<vector<ll>>> card(8889);
set<pair<ll, ll>> take;
vector<ll> A(88);
vector<ll> c(88, 0);
ll N;
ll pigeon = 0;

void dfs(ll x, bool ch){
    if(pigeon >= 8890){
        return;
    }
    if(ch){
        if(c.at(x) > 0){
            return;
        }
        take.insert({x, A.at(x)});
        for(edge e : graph.at(x)){
            c.at(e.to)++;
        }
    }
    if(x == N-1){
        ll sum = 0;
        vector<ll> S(0);
        for(auto p : take){
            sum += p.second;
            S.push_back(p.first);
        }
        card.at(sum).insert(S);
        pigeon++;
    }
    else{
        dfs(x+1, true);
        dfs(x+1, false);
    }
    if(ch){
        for(edge e : graph.at(x)){
            c.at(e.to)--;
        }
        take.erase({x, A.at(x)});
    }
}

int main()
{
    ll Q;
    cin >> N >> Q;
    graph.resize(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> x(Q), y(Q);
    rep(i, Q){
        cin >> x.at(i) >> y.at(i);
        x.at(i)--;
        y.at(i)--;
        graph.at(x.at(i)).push_back({y.at(i)});
    }
    dfs(0, true);
    dfs(0, false);
    rep(i, 8889){
        if(sz(card.at(i)) >= 2){
            ll cnt = 0;
            for(auto P : card.at(i)){
                ll x = sz(P);
                cout << x << '\n';
                rep(j, x-1){
                    cout << P.at(j)+1 << ' ';
                }
                cout << P.at(x-1)+1 << '\n';
                cnt++;
                if(cnt == 2){
                    return 0;
                }
            }
        }
    }
}