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
  int64_t N;
  cin >> N;
  if(N % 2 == 1){
    cout << 0 << endl;
    return 0;
  }
  int64_t cnt = 0;
  bool fst = true;
  while(N > 0){
    if(fst){
      fst = false;
      N /= 10;
    }
    cnt += N;
    N /= 5;
  }
  cout << cnt << endl;
}