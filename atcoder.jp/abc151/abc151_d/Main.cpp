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
vector<string> S;
queue<pair<int, int>> det;
vector<vector<int>> mv(20, vector<int>(20, INF));

void bfs(int x, int y, int d){
  if(x < 0 || x >= H || y < 0 || y >= W){
    return;
  }
  if(mv.at(x).at(y) < INF){
    return;
  }
  if(S.at(x).at(y) == '#'){
    return;
  }
  mv.at(x).at(y) = d + 1;
  det.push(make_pair(x, y));
}

int main(){
  cin >> H >> W;
  S.resize(H);
  rep(i, H){
    cin >> S.at(i);
  }
  int ans = 0;
  rep(i, H){
    rep(j, W){
      rep(k, H){
        rep(l, W){
          mv.at(k).at(l) = INF;
        }
      }
      if(S.at(i).at(j) == '#'){
        continue;
      }
      bfs(i, j, -1);
      while(!det.empty()){
        pair<int, int> q = make_pair(det.front().first, det.front().second);
        det.pop();
        int d = mv.at(q.first).at(q.second);
        bfs(q.first+1, q.second, d);
        bfs(q.first-1, q.second, d);
        bfs(q.first, q.second+1, d);
        bfs(q.first, q.second-1, d);
      }
      rep(k, H){
        rep(l, W){
          if(mv.at(k).at(l) < INF){
            chmax(ans, mv.at(k).at(l));
          }
        }
      }
    }
  }
  cout << ans << endl;          
}