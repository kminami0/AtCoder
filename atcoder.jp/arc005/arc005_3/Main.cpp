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

int H, W;
vector<string> c;
vector<vector<int>> mv(500, vector<int>(500, INF));
deque<pair<int, int>> det;

void bfs(int x, int y, int d){
  if(x < 0 || x >= H || y < 0 || y >= W){
    return;
  }
  if(c.at(x).at(y) == '#' && d >= 2){
    return;
  }
  if(mv.at(x).at(y) < INF){
    return;
  }
  if(c.at(x).at(y) == '#'){
    chmin(mv.at(x).at(y), d + 1);
    det.push_back(make_pair(x, y));
  }
  else{
    chmin(mv.at(x).at(y), d);
    det.push_front(make_pair(x, y));
  }
}

int main(){
  cin >> H >> W;
  c.resize(H);
  rep(i, H){
    cin >> c.at(i);
  }
  int gx, gy;
  rep(i, H){
    rep(j, W){
      if(c.at(i).at(j) == 's'){
        bfs(i, j, 0);
      }
      if(c.at(i).at(j) == 'g'){
        gx = i;
        gy = j;
      }
    }
  }
  while(!det.empty()){
    pair<int, int> q = make_pair(det.front().first, det.front().second);
    det.pop_front();
    int d = mv.at(q.first).at(q.second);
    bfs(q.first+1, q.second, d);
    bfs(q.first-1, q.second, d);
    bfs(q.first, q.second+1, d);
    bfs(q.first, q.second-1, d);
  }
  if(mv.at(gx).at(gy) <= 2){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}