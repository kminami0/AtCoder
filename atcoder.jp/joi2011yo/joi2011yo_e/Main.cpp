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
vector<queue<pair<int, int>>> det;
vector<map<pair<int, int>, int>> mv;
int H, W;

void bfs(int x, int y, int d, int i){
  if(x < 0 || x >= H){
    return;
  }
  if(y < 0 || y >= W){
    return;
  }
  if(c.at(x).at(y) == 'X'){
    return;
  }
  pair<int, int> p = make_pair(x, y);
  if(mv.at(i).count(p)){
    return;
  }
  mv.at(i)[p] = d + 1;
  det.at(i).push(p);
}

int main(){
  int N;
  cin >> H >> W >> N;
  c.resize(H);
  mv.resize(N);
  det.resize(N);
  rep(i, H){
    cin >> c.at(i);
  }
  vector<int> gx(N);
  vector<int> gy(N);
  rep(i, N){
    rep(j, H){
      rep(k, W){
        if(c.at(j).at(k) == i+1 + '0'){
          gx.at(i) = j;
          gy.at(i) =k;
        }
      }
    }
  }
  vector<pair<int, int>> g(N);
  rep(i, N){
    g.at(i) = make_pair(gx.at(i), gy.at(i));
  }
  int ans = 0;
  vector<int> sx(N);
  vector<int> sy(N);
  rep(i, H){
    rep(j, W){
      if(c.at(i).at(j) == 'S'){
        sx.at(0) = i;
        sy.at(0) = j;
      }
    }
  }
  rep(i, N-1){
    sx.at(i+1) = gx.at(i);
    sy.at(i+1) = gy.at(i);
  }
  bool sc = false;
  rep(i, N){
    sc = false;
    while(!mv.at(i).count(g.at(i))){
      if(!sc){
        bfs(sx.at(i), sy.at(i), -1, i);
        sc = true;
      }
      else{
        pair<int, int> q = make_pair(det.at(i).front().first, det.at(i).front().second);
        det.at(i).pop();
        bfs(q.first+1, q.second, mv.at(i).at(q), i);
        bfs(q.first-1, q.second, mv.at(i).at(q), i);
        bfs(q.first, q.second+1, mv.at(i).at(q), i);
        bfs(q.first, q.second-1, mv.at(i).at(q), i);
      }
    }
    ans += mv.at(i).at(g.at(i));
  }
  cout << ans << endl;
}