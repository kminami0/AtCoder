#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int X, Y;
  cin >> X >> Y;
  int m = 0;
  if(X==1){
    m+=300000;
  }
  else if(X==2){
    m+=200000;
  }
  else if(X==3){
    m+=100000;
  }
  if(Y==1){
    m+=300000;
  }
  else if(Y==2){
    m+=200000;
  }
  else if(Y==3){
    m+=100000;
  }
  if(X==1 && Y==1){
    m+=400000;
  }
  cout << m << endl;
}