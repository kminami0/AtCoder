#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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
};
vector<vector<edge>> graph;

//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    map<ll, ll> loop;
    rep(i, M){
        ll A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        graph.at(A).push_back({B, C});
        if(A == B){
            if(loop.count(A)){
                chmin(loop.at(A), C);
            }
            else{
                loop[A] = C;
            }
        }
    }
    vector<vector<ll>> cost(N, vector<ll>(N, INF));
    rep(i, N){
        cost.at(i).at(i) = 0;
    }
    rep(i, N){
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        q.push({0, i});
        while(!q.empty()){
            pair<ll, ll> p = q.top();
            q.pop();
            if(cost.at(i).at(p.second) < p.first){
                continue;
            }
            else{
                cost.at(i).at(p.second) = p.first;
            }
            for(auto e : graph.at(p.second)){
                ll d = cost.at(i).at(p.second) + e.time;
                if(chmin(cost.at(i).at(e.to), d)){
                    q.push({cost.at(i).at(e.to), e.to});
                }
            }
        }
    }
    rep(i, N){
        ll ans = INF;
        rep(j, N){
            if(j == i){
                continue;
            }
            chmin(ans, cost.at(i).at(j)+cost.at(j).at(i));
        }
        if(loop.count(i)){
            chmin(ans, loop.at(i));
        }
        if(ans == INF){
            cout << -1 << '\n';
        }
        else{
            cout << ans << '\n';
        }
    }
}