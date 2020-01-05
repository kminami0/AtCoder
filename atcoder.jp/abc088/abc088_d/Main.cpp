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

int H, W;
vector<string> s;
queue<pair<int, int>> det;
map<pair<int, int>, int> mv;

void bfs(int x, int y, int d){
  if(x < 0 || x >= H){
    return;
  }
  if(y < 0 || y >= W){
    return;
  }
  if(s.at(x).at(y) == '#'){
    return;
  }
  pair<int, int> p = make_pair(x, y);
  if(mv.count(p)){
    return;
  }
  mv[p] = d + 1;
  det.push(p);
}

int main(){
  cin >> H >> W;
  s.resize(H);
  rep(i, H){
    cin >> s.at(i);
  }
  pair<int, int> g = make_pair(H-1, W-1);
  int numw = 0;
  rep(i, H){
    rep(j, W){
      if(s.at(i).at(j) == '.'){
        numw++;
      }
    }
  }
  bfs(0, 0, -1);
  while(!mv.count(g) && !det.empty()){
    pair<int, int> q = make_pair(det.front().first, det.front().second);
    det.pop();
    bfs(q.first+1, q.second, mv.at(q));
    bfs(q.first-1, q.second, mv.at(q));
    bfs(q.first, q.second+1, mv.at(q));
    bfs(q.first, q.second-1, mv.at(q));
  }
  if(!mv.count(g)){
    cout << -1 << endl;
  }
  else{
    cout << numw-mv.at(g)-1 << endl;
  }
}