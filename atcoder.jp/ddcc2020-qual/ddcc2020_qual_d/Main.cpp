#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int64_t M;
  cin >> M;
  vector<int64_t> d(M);
  vector<int64_t> c(M);
  rep(i, M){
    cin >> d.at(i) >> c.at(i);
  }
  int64_t digit = 0;
  int64_t sum = 0;
  rep(i, M){
    digit += c.at(i);
    sum += d.at(i) * c.at(i);
  }
  cout << digit - 1 + (sum-1) / 9 << endl;
}
