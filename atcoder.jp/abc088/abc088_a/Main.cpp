#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(){
  int N, A;
  cin >> N >> A;
  if(A >= N % 500){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}