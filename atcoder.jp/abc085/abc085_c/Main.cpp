#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int64_t N, Y;
  cin >> N >> Y;
  rep(i, N+1){
    rep(j, N+1-i){
      if(10000*i + 5000*j + 1000*(N-i-j) == Y){
        cout << i << " " << j << " " << N-i-j << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
}