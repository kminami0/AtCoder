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
  vector<int> A(N);
  rep(i, N){
    cin >> A.at(i);
  }
  vector<int> num(N, 0);
  rep(i, N){
    num.at(A.at(i)-1)++;
  }
  sort(all(num));
  reverse(all(num));
  int pos = N;
  rep(i, N){
    if(num.at(i) == 0){
      pos = i;
      break;
    }
  }
  int cnt = 0;
  if(pos <= K){
    cout << 0 << endl;
  }
  else{
    while(pos > K){
      cnt += num.at(pos-1);
      pos--;
    }
    cout << cnt << endl;
  }
}