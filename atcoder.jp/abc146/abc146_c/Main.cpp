#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int64_t A, B, X;
  cin >> A >> B >> X;
  if(A * 1000000000 + B * 10 <= X){
    cout << 1000000000 << endl;
    return 0;
  }
  int64_t ans = 0;
  rep(i, 9){
    if((X - B * (i + 1)) / A < pow(10, i+1) && pow(10, i) <= (X - B * (i + 1)) / A){
      ans = (X - B * (i + 1)) / A;
    }
    else if(pow(10, i+1) <= (X - B * (i + 1)) / A){
      ans = pow(10, i+1) -1;
    }
  }
  cout << ans << endl;
}