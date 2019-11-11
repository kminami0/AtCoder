#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int F(int64_t A, int64_t B){
  return log10(max(A, B))+1;
}

int main(){
  int64_t N;
  cin >> N;
  int ans = 11;
  rep2(i, 1, pow(N, 0.5)+1){
    if(N % i == 0){
      chmin(ans, F(i, N/i));
    }
  }
  cout << ans << endl;
}