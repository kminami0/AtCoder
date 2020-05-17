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

struct edge{
  ll to;
};

vector<vector<edge>> graph;
map<ll, pair<ll, ll>> mv;
queue<ll> det;

void bfs(ll x, ll d, ll p){
  if(mv.count(x)){
    return;
  }
  mv[x] = make_pair(d + 1, p);
  det.push(x);
}

int main(){
  ll N, M;
  cin >> N >> M;
  graph.resize(N);
  vector<ll> A(M), B(M);
  rep(i, M){
    cin >> A.at(i) >> B.at(i);
    A.at(i)--;
    B.at(i)--;
    graph.at(A.at(i)).push_back({B.at(i)});
    graph.at(B.at(i)).push_back({A.at(i)});
  }
  mv[0] = make_pair(0, -1);
  det.push(0);
  while(!det.empty()){
    ll x = det.front();
    det.pop();
    for(auto e : graph.at(x)){
      bfs(e.to, mv.at(x).first, x);
    }
  }
  cout << "Yes" << endl;
  rep(i, N-1){
    cout << mv.at(i+1).second + 1 << endl;
  }
}