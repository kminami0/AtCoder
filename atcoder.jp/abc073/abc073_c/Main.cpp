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
  vector<int64_t> A(N);
  rep(i, N){
    cin >> A.at(i);
  }
  map<int64_t, int64_t> buc;
  rep(i, N){
    buc[A.at(i)]++;
  }
  int64_t cnt = 0;
  for(auto p:buc){
    if(p.second % 2 == 1){
      cnt++;
    }
  }
  cout << cnt << endl;
}