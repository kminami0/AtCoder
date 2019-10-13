#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main(){
  int64_t a, b, x;
  cin >> a >> b >> x;
  int64_t cnt = 0;
  
  if(a % x == 0){
    cnt = (b-a) / x + 1;
  }
  else if(a + x - (a % x) <= b){
    cnt = (b-(a + x - (a % x))) / x + 1;
  }
  
  cout << cnt << endl;
}
  