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
  int A, B;
  cin >> A >> B;
  if(A != 1 && B != 1){
    cout << 1 << endl;
  }
  if(A != 2 && B != 2){
    cout << 2 << endl;
  }
  if(A != 3 && B != 3){
    cout << 3 << endl;
  }
}