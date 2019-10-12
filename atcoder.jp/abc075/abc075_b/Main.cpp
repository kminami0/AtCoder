#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i, H){
    cin >> S.at(i);
  }
  int count = 0;
  vector<int> dx = {1,1,0,-1,-1,-1,0,1};
  vector<int> dy = {0,1,1,1,0,-1,-1,-1};
  
  rep(i, H){
    rep(j, W){
      if(S.at(i).at(j) == '.'){
        rep(k, 8){
          if(0 <= i+dx.at(k) && i+dx.at(k) < H && 0 <= j+dy.at(k) && j+dy.at(k) < W){
            if(S.at(i+dx.at(k)).at(j+dy.at(k)) == '#'){
              count++;
            }
          }
        }
        S.at(i).at(j) = '0' + count;
        count = 0;
      }
    }
  }
  
  rep(i, H){
    cout << S.at(i) << endl;
  }
}