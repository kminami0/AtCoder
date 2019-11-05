#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int64_t N, x;
  cin >> N >> x;
  vector<int64_t> a(N);
  rep(i, N){
    cin >> a.at(i);
  }
  if(accumulate(all(a), 0LL) <  x){
    cout << N-1 << endl;
    return 0;
  }
  sort(all(a));
  int64_t cnt = 0;
  int64_t dist = 0;
  int64_t j = 0;
  while(j <= N-1 && dist + a.at(j) <= x){
    cnt++;
    dist += a.at(j);
    j++;
  }
  cout << cnt << endl;
}