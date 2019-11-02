#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)

int main(){
  int N;
  cin >> N;
  int cnt = 0;
  while(pow(2, cnt) <= N){
    cnt++;
  }
  cnt--;
  cout << pow(2, cnt) << endl;
}