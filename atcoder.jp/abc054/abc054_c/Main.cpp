#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000000
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

int main(){
  int N, M;
  cin >> N >> M;
  graph.resize(N);
  rep(i, N){
    vector<edge> vt(0);
    graph.at(i) = make_pair(i, vt);
  }
  vector<int> a(M);
  vector<int> b(M);
  rep(i, M){
    cin >> a.at(i) >> b.at(i);
    a.at(i)--;
    b.at(i)--;
    graph.at(a.at(i)).second.push_back({b.at(i), i});
    graph.at(b.at(i)).second.push_back({a.at(i), i});
  }
  int ans = 0;
  bool cnc = false;
  sort(all(graph));
  do {
    if(graph.at(0).first != 0){
      continue;
    }
    rep(i, N-1){
      rep(j, sz(graph.at(i).second)){
        if(graph.at(i).second.at(j).to == graph.at(i+1).first){
          cnc = true;
        }
      }
      if(!cnc){
        break;
      }
      if(i == N-2){
        ans++;
      }
      cnc = false;
    }
  } while (next_permutation(all(graph)));
  cout << ans << endl;
}