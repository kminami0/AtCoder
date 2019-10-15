#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  int min = N;
  int cnt = 0;
  
  rep(i, N){
    if(i == 0){
      rep(j, N-1){
        if(S.at(j+1) == 'E'){
          cnt++;
        }
      }
      min = cnt;
    }
    else{
      if(S.at(i-1) == 'W'){
        cnt++;
      }
      if(S.at(i) == 'E'){
        cnt--;
      }
      if(cnt < min){
        min = cnt;
      }
    }
  }
  
  cout << min << endl;
}