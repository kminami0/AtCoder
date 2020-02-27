#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000009
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
  int to;
  int id;
  bool operator<(const edge &another) const{
    return id < another.id;
  };
};

vector<pair<int, vector<edge>>> graph;
vector<ll> ins;

int main(){
  ll N, M;
  cin >> N >> M;
  graph.resize(N);
  ins.resize(N);
  rep(i, N){
    vector<edge> vt(0);
    graph.at(i) = make_pair(i, vt);
    ins.at(i) = 0;
  }
  vector<int> x(M), y(M);
  queue<ll> S;
  rep(i, M){
    cin >> x.at(i) >> y.at(i);
    x.at(i)--;
    y.at(i)--;
    graph.at(x.at(i)).second.push_back({y.at(i), i});
    ins.at(y.at(i))++;
  }
  rep(i, N){
    if(ins.at(i) == 0){
      S.push(i);
    }
  }
  vector<ll> topo(0);
  while(!S.empty()){
    ll v = S.front();
    S.pop();
    topo.push_back(v);
    for(auto e : graph.at(v).second){
      ins.at(e.to)--;
      if(ins.at(e.to) == 0){
        S.push(e.to);
      }
    }
  }
  vector<ll> cost(N, 0);
  for(auto i : topo){
    for(auto e : graph.at(i).second){
      chmax(cost.at(e.to), cost.at(i)+1);
    }
  }
  ll ans = 0;
  rep(i, N){
    chmax(ans, cost.at(i));
  }
  cout << ans << endl;
}