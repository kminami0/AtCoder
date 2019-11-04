#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int N;
  cin >> N;
  int M = N;
  int f = 0;
  rep(i, 9){
    f += N % 10;
    N /= 10;
  }
  if(M % f == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}