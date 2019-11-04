#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int K, S;
  cin >> K >> S;
  int cnt = 0;
  rep(i, K+1){
    rep(j, K+1){
      if(S-i-j >= 0 && S-i-j <= K){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}