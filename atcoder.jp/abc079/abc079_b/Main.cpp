#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<uint64_t> Lucas(N+1);
  Lucas.at(0) = 2;
  Lucas.at(1) = 1;
  
  if(N==0){
    cout << Lucas.at(0) << endl;
  }
  else if(N==1){
    cout << Lucas.at(1) << endl;
  }
  else {
    rep2(i, 2, N+1){
      Lucas.at(i) = Lucas.at(i-1) + Lucas.at(i-2);
    }
    cout << Lucas.at(N) << endl;
  }
}
