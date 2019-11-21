#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int64_t N;
  cin >> N;
  vector<int64_t> t(N);
  rep(i, N){
    cin >> t.at(i);
  }
  int64_t gr0 = 0;
  int64_t gr1 = 0;
  int64_t ans = 1001001001;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    bitset<4> s(tmp);
    rep(i, N){
      if(s.test(i)){
        gr1 += t.at(i);
      }
      else{
        gr0 += t.at(i);
      }
    }
    chmin(ans, max(gr0, gr1));
    gr0 = 0;
    gr1 = 0;
  }
  cout << ans << endl;
}