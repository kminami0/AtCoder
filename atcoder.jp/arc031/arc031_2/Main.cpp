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

vector<vector<bool>> p(10, vector<bool>(10, false));
int gx = 0;
int gy = 0;
vector<string> c(10);

void dfs(int x, int y){
  if(p.at(gx).at(gy) == true){
    return;
  }
  if(x < 0 || x >= 10){
    return;
  }
  if(y < 0 || y >= 10){
    return;
  }
  if(c.at(x).at(y) == 'x'){
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
  rep(i, 10){
    cin >> c.at(i);
  }
  int fx = 0;
  int fy = 0;
  bool flg = false;
  rep(i, 10){
    rep(j, 10){
      if(c.at(i).at(j) == 'o'){
        fx = i;
        fy = j;
        flg = true;
        break;
      }
    }
    if(flg){
      break;
    }
  }
  bool fill = false;
  flg = false;
  rep(i, 10){
    rep(j, 10){
      if(c.at(i).at(j) == 'x'){
        c.at(i).at(j) = 'o';
        fill = true;
      }
      if(fill){
        rep(k, 10){
          rep(l, 10){
            if(c.at(k).at(l) == 'x'){
              if(k == 9 && l == 9){
                cout << "YES" << endl;
                return 0;
              }
              continue;
            }
            gx = k;
            gy = l;
            dfs(fx, fy);
            if(p.at(gx).at(gy) == false){
              fill = false;
              c.at(i).at(j) = 'x';
              rep(m, 10){
                rep(n, 10){
                  p.at(m).at(n) = false;
                }
              }
              flg = true;
              break;
            }
            rep(m, 10){
              rep(n, 10){
                p.at(m).at(n) = false;
              }
            }
            if(k == 9 && l == 9){
              cout << "YES" << endl;
              return 0;
            }
          }
          if(flg){
            flg = false;
            break;
          }
        }
      }
    }
  }
  cout << "NO" << endl;
}