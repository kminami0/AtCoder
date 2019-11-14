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
  vector<int> A(N);
  rep(i, N){
    cin >> A.at(i);
  }
  bool up = false;
  bool unk = true;
  int cnt = 0;
  rep(i, N-1){
    if(unk){
      if(A.at(i) < A.at(i+1)){
        unk = false;
        up = true;
      }
      else if(A.at(i) > A.at(i+1)){
        unk = false;
        up = false;
      }
    }
    else if(up){
      if(A.at(i) > A.at(i+1)){
        unk = true;
        cnt++;
      }
    }
    else{
      if(A.at(i) < A.at(i+1)){
        unk = true;
        cnt++;
      }
    }
  }
  cout << cnt+1 << endl;
}