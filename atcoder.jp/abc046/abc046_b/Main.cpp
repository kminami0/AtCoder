#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main(){
  int N, K;
  cin >> N >> K;
  int cnt = 0;
  rep(i, N){
    if(i==0){
      cnt = K;
    }
    else{
      cnt *= K-1;
    }
  }
  cout << cnt << endl;
}