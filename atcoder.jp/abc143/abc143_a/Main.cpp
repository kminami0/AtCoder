#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int A, B;
  cin >> A >> B;
  cout << max(A-2*B, 0) << endl;
}