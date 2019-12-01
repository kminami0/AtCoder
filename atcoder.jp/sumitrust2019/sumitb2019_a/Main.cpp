#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int M1, D1, M2, D2;
  cin >> M1 >> D1 >> M2 >> D2;
  if(M2 == M1+1){
    cout << 1 << endl;
  }
  else if(M1 == 12 && M2 == 1){
    cout << 1 << endl;
  }
  else{
    cout << 0 << endl;
  }
}