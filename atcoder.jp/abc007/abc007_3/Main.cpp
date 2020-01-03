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

vector<string> c;
queue<pair<int, int>> det;
map<pair<int, int>, int> mv;
int gy, gx;

void bfs(int y, int x, int d){
  if(c.at(y).at(x) == '#'){
    return;
  }
  pair<int, int> p = make_pair(y, x);
  if(mv.count(p)){
    return;
  }
  mv[p] = d + 1;
  det.push(p);
}

int main(){
  int R, C, sy, sx;
  cin >> R >> C >> sy >> sx >> gy >> gx;
  sy--;
  sx--;
  gy--;
  gx--;
  c.resize(R);
  rep(i, R){
    cin >> c.at(i);
  }
  pair<int, int> g = make_pair(gy, gx);
  bool sc = false;
  while(!mv.count(g)){
    if(!sc){
      bfs(sy, sx, -1);
      sc = true;
    }
    else{
      pair<int, int> q = make_pair(det.front().first, det.front().second);
      det.pop();
      bfs(q.first+1, q.second, mv.at(q));
      bfs(q.first-1, q.second, mv.at(q));
      bfs(q.first, q.second+1, mv.at(q));
      bfs(q.first, q.second-1, mv.at(q));
    }
  }
  cout << mv.at(g) << endl;
}