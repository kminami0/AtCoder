#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int N;
  cin >> N;
  int ans = 900;
  rep2(i, 1, N){
    string s = to_string(i);
    string t = to_string(N-i);
//    cout << s << " " << t << endl;
    int sdA = 0, sdB = 0;
    rep(j, s.size()){
//      cout << j << ":" << s.at(j) - '0' << endl;
      sdA += s.at(j) - '0';
    }
    rep(j, t.size()){
      sdB += t.at(j) - '0';
    }
//    cout << sdA << " " << sdB << endl;
    chmin(ans, (sdA+sdB));
  }
  cout << ans << endl;
}