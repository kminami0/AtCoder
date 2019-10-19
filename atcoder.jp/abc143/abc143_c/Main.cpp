#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N;
  string S;
  cin >> N;
  cin >> S;
  int cnt = 1;
  
  rep(i, N-1){
    if(S.at(i) != S.at(i+1)){
      cnt++;
    }
  }
  cout << cnt << endl;
}