#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int64_t A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int64_t ans = 1001001001;
  rep(i, max(X, Y)+1){
    if(i == max(X, Y)){
      chmin(ans, 2 * i * C);
    }
    else if(min(X, Y) <= i){
      if(X <= Y){
        chmin(ans, 2 * i * C + (Y - i) * B);
      }
      else{
        chmin(ans, 2 * i * C + (X - i) * A);
      }
    }
    else{
      chmin(ans, 2 * i * C + (X - i) * A + (Y - i) * B);
    }
  }
  cout << ans << endl;
}