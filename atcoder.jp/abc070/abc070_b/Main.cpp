#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int t = 0;
  int cnt = 0;
  bool pushA = false;
  bool pushB = false;
  while(t <= max(B, D)){
    if(t == A){
      pushA = true;
    }
    if(t == B){
      pushA = false;
    }
    if(t == C){
      pushB = true;
    }
    if(t == D){
      pushB = false;
    }
    if(pushA && pushB){
      cnt++;
    }
    t++;
  }
  cout << cnt << endl;
}