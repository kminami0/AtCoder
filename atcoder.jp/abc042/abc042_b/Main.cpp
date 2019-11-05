#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int N, L;
  cin >> N >> L;
  vector<string> S(N);
  rep(i, N){
    cin >> S.at(i);
  }
  sort(all(S));
  string ans = "";
  rep(i, N){
    ans += S.at(i);
  }
  cout << ans << endl;
}