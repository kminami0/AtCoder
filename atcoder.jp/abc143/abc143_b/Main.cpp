#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N;
  cin >> N;
  vector<int> d(N);
  rep(i, N){
    cin >> d.at(i);
  }
  int res = 0;
  rep(i, N){
    rep(j, N-i-1){
      res += d.at(i) * d.at(i+j+1);
    }
  }
  cout << res << endl;
}