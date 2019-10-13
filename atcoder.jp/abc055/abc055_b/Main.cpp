#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main(){
  int N;
  cin >> N;
  int64_t power = 1;
  rep(i, N){
    power *= (i+1);
    power %= 1000000007;
  }
  cout << power << endl;
}