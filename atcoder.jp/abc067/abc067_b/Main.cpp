#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> l(N);
  rep(i, N){
    cin >> l.at(i);
  }
  sort(all(l));
  reverse(all(l));
  int len = 0;
  rep(i, K){
    len += l.at(i);
  }
  cout << len << endl;
}