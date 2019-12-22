#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int64_t N;
  cin >> N;
  vector<int64_t> a(N);
  rep(i, N){
    cin >> a.at(i);
  }
  int64_t cnt = 0;
  int64_t num = 1;
  rep(i, N){
    if(a.at(i) != num){
      cnt++;
    }
    else{
      num++;
    }
  }
  if(cnt == N){
    cout << -1 << endl;
  }
  else{
    cout << cnt << endl;
  }
}