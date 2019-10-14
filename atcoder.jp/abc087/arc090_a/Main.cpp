#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N;
  cin >> N;
  vector<vector<int>> A(2, vector<int>(N));
  
  rep(i, 2){
    rep(j, N){
      cin >> A.at(i).at(j);
    }
  }
  
  int x = 0;
  int y = 0;
  int cnt = A.at(0).at(0);
  int max = 0;
  
  rep(i, N){
    while(x != 1 || y != N-1){
      if(x == 0 && y == i){
        x++;
        cnt += A.at(x).at(y);
      }
      else{
        y++;
        cnt += A.at(x).at(y);
      }
    }
    if(cnt > max){
      max = cnt;
    }
    x = 0;
    y = 0;
    cnt = A.at(0).at(0);
  }
  
  cout << max << endl;
  
}