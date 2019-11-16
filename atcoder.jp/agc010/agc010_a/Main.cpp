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
  vector<int64_t> A(N);
  int cnt = 0;
  rep(i, N){
    cin >> A.at(i);
    if(A.at(i) % 2 == 1){
      cnt++;
    }
  }
  if(cnt % 2 == 0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}