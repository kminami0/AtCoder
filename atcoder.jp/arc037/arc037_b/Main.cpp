#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
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
};

vector<vector<edge>> graph;
vector<bool> rc(100, false);

bool dfs(int x, int p = -1){
  bool ok = true;
  if(rc.at(x)){
    return false;
  }
  rep(i, sz(graph.at(x))) {
    rc.at(x) = true;
    if (graph.at(x).at(i).to == p) {
			continue;
    }
    ok = ok && dfs(graph.at(x).at(i).to, x);
  }
  return ok;
} 

int main(){
  int N, M;
  cin >> N >> M;
  graph.resize(N);
  vector<int> u(M);
  vector<int> v(M);
  rep(i, M){
    cin >> u.at(i) >> v.at(i);
    u.at(i)--;
    v.at(i)--;
    graph.at(u.at(i)).push_back({ v.at(i), i });
    graph.at(v.at(i)).push_back({ u.at(i), i });
  }
  int ans = 0;
  rep(i, N){
    if(rc.at(i)){
      continue;
    }
    if(dfs(i)){
      ans++;
    }
  }
  cout << ans << endl;
}