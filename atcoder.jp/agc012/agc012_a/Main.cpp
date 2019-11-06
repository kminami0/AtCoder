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
  vector<int> a(3*N);
  rep(i, 3*N){
    cin >> a.at(i);
  }
  sort(all(a));
  reverse(all(a));
  int64_t pow = 0;
  rep(i, N){
    pow += a.at(2*i+1);
  }
  cout << pow << endl;
}