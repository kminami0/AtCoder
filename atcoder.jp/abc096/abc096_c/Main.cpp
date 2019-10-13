#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> s(H);
  rep(i, H){
    cin >> s.at(i);
  }
  vector<int> dx = {1,0,-1,0};
  vector<int> dy = {0,1,0,-1};
  bool pos = true;
  
  rep(i, H){
    rep(j, W){
      if(s.at(i).at(j) == '#'){
        rep(k, 4){
          if(0 <= i+dx.at(k) && i+dx.at(k) < H && 0 <= j+dy.at(k) && j+dy.at(k) < W){
            if(s.at(i+dx.at(k)).at(j+dy.at(k)) == '#'){
              break;
            }
          }
          if(k == 3){
            cout << "No" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "Yes" << endl;
}