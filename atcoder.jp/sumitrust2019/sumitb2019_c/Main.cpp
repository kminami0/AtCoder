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
  int64_t X;
  cin >> X;
  if(X % 100 == 0){
    cout << 1 << endl;
  }
  else if(((X % 100) + 4) / 5 <= X / 100){
    cout << 1 << endl;
  }
  else{
    cout << 0 << endl;
  }
}