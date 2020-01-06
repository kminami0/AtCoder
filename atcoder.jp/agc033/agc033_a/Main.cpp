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
queue<pair<int, int>> det;
vector<vector<int>> mv(1000, vector<int>(1000, INF));
int ans = 0;

void bfs(int x, int y, int d){
  if(x < 0 || x >= H || y < 0 || y >= W){
    return;
  }
  if(mv.at(x).at(y) < INF){
    return;
  }
  mv.at(x).at(y) = d + 1;
  chmax(ans, d+1);
  det.push(make_pair(x, y));
}

int main(){
  cin >> H >> W;
  vector<string> A(H);
  rep(i, H){
    cin >> A.at(i);
  }
  vector<pair<int, int>> s;
  rep(i, H){
    rep(j, W){
      if(A.at(i).at(j) == '#'){
        s.push_back(make_pair(i, j));
      }
    }
  }
  rep(k, sz(s)){
    bfs(s.at(k).first, s.at(k).second, -1);
  }

  while(!det.empty()){
    pair<int, int> q = make_pair(det.front().first, det.front().second);
    det.pop();
    int d = mv.at(q.first).at(q.second);
    bfs(q.first+1, q.second, d);
    bfs(q.first-1, q.second, d);
    bfs(q.first, q.second+1, d);
    bfs(q.first, q.second-1, d);
  }
  cout << ans << endl;
}