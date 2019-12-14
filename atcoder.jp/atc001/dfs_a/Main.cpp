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
vector<vector<bool>> p(500, vector<bool>(500, false));
int gx = 0;
int gy = 0;
vector<string> c(500, "");

void dfs(int x, int y){
  if(p.at(gx).at(gy) == true){
    return;
  }
  if(x < 0 || x >= H){
    return;
  }
  if(y < 0 || y >= W){
    return;
  }
  if(c.at(x).at(y) == '#'){
    return;
  }
  if(p.at(x).at(y) == true){
    return;
  }
  p.at(x).at(y) = true;
  dfs(x+1, y);
  dfs(x-1, y);
  dfs(x, y+1);
  dfs(x, y-1);
}

int main(){
  cin >> H >> W;
  rep(i, H){
    cin >> c.at(i);
  }
  int sx = 0;
  int sy = 0;
  rep(i, H){
    rep(j, W){
      if(c.at(i).at(j) == 's'){
        sx = i;
        sy = j;
      }
    }
  }
  rep(i, H){
    rep(j, W){
      if(c.at(i).at(j) == 'g'){
        gx = i;
        gy = j;
      }
    }
  }
  dfs(sx, sy);
  if(p.at(gx).at(gy) == true){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}