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
vector<vector<edge>> graph;
vector<vector<edge>> rgraph;

queue<ll> q;
vector<ll> prnt;

void bfs(ll x, ll p){
    prnt.at(x) = p;
    q.push(x);
}

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    rgraph.resize(N);
    rep(i, N-1+M){
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        graph.at(A).push_back({B});
        rgraph.at(B).push_back({A});
    }
    queue<ll> S;
    vector<ll> inegdes(N, 0);
    rep(i, N){
        inegdes.at(i) = sz(rgraph.at(i));
    }
    rep(i, N){
        if(inegdes.at(i) == 0){
            S.push(i);
        }
    }
    map<ll, ll> topo;
    ll c = 0;
    while(!S.empty()){
        ll v = S.front();
        S.pop();
        topo[v] = c;
        c++;
        for(auto e : graph.at(v)){
            inegdes.at(e.to)--;
            if(inegdes.at(e.to) == 0){
                S.push(e.to);
            }
        }
    }
    rep(i, N){
        ll p = -1;
        ll q = -1;
        for(auto e : rgraph.at(i)){
            if(chmax(p, topo.at(e.to))){
                q = e.to;
            }
        }
        cout << q+1 << endl;
    }
}