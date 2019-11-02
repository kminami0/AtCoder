#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int N, X;
  cin >> N >> X;
  vector<int> m(N);
  rep(i, N){
    cin >> m.at(i);
  }
  int nec = accumulate(all(m), 0);
  X -= nec;
  int mini = m.at(0);
  rep(i, N){
    chmin(mini, m.at(i));
  }
  int res = X / mini;
  cout << N + res << endl;
}