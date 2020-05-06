#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14 100兆
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

struct edge {
  ll to;
  ll dst;
};

vector<vector<edge>> graph;
vector<vector<ll>> cost(100, vector<ll>(100, INF));

void dijkstra(ll x){
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  q.push(make_pair(0, x));
  while(!q.empty()){
    pair<ll, ll> p = q.top();
    q.pop();
    rep(i, sz(graph.at(p.second))){
      if(chmin(cost.at(x).at(graph.at(p.second).at(i).to), cost.at(x).at(p.second)+graph.at(p.second).at(i).dst)){
        q.push(make_pair(cost.at(x).at(graph.at(p.second).at(i).to), graph.at(p.second).at(i).to));
      }
    }
  }
}

  

int main(){
  ll n, k;
  cin >> n >> k;
  graph.resize(n);
  rep(i, n){
    cost.at(i).at(i) = 0;
  }
  rep(i, k){
    ll s;
    cin >> s;
    if(s == 0){
      ll a, b;
      cin >> a >> b;
      a--;
      b--;
      dijkstra(a);
      if(cost.at(a).at(b) == INF){
        cout << -1 << endl;
      }
      else{
        cout << cost.at(a).at(b) << endl;
      }
    }
    else{
      ll c, d, e;
      cin >> c >> d >> e;
      c--;
      d--;
      graph.at(c).push_back({d, e});
      graph.at(d).push_back({c, e});
      rep(j, n){
        rep(l, n){
          if(j == l){
            continue;
          }
          cost.at(j).at(l) = INF;
        }
      }
    }
  }
}