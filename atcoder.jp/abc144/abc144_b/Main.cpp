#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(){
  int N;
  cin >> N;
  rep(i, 9){
    if(N % (i+1) == 0 && N / (i+1) <= 9){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}