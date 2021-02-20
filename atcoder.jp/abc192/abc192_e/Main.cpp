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
  ll time;
  ll dep;
};
vector<vector<edge>> graph;

int main()
{
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    graph.resize(N);
    X--;
    Y--;
    vector<ll> A(M), B(M), T(M), K(M);
    rep(i, M){
        cin >> A.at(i) >> B.at(i) >> T.at(i) >> K.at(i);
        A.at(i)--;
        B.at(i)--;
        graph.at(A.at(i)).push_back({B.at(i), T.at(i), K.at(i)});
        graph.at(B.at(i)).push_back({A.at(i), T.at(i), K.at(i)});
    }
    vector<ll> cost(N, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, X});
    while(!q.empty()){
        pair<ll, ll> p = q.top();
        q.pop();
        if(cost.at(p.second) < p.first){
            continue;
        }
        else{
            cost.at(p.second) = p.first;
        }
        for(auto e : graph.at(p.second)){
            ll d;
            if(cost.at(p.second) % e.dep == 0){
                d = cost.at(p.second) + e.time;
            }
            else{
                d = cost.at(p.second) + e.time + e.dep - (cost.at(p.second) % e.dep);
            }
            if(chmin(cost.at(e.to), d)){
                q.push({cost.at(e.to), e.to});
            }
        }
    }
    if(cost.at(Y) == INF){
        cout << -1 << '\n';
    }
    else{
        cout << cost.at(Y) << '\n';
    }
}