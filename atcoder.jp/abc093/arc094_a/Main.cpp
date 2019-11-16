#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  int cnt = 0;
  if((A+B)%2 == 1 && (A+C)%2 == 1){
    B++;
    C++;
    cnt++;
  }
  else if((B+C)%2 == 1 && (B+A)%2 == 1){
    C++;
    A++;
    cnt++;
  }
  else if((C+A)%2 == 1 && (C+B)%2 == 1){
    A++;
    B++;
    cnt++;
  }
  if(A >= B && A >= C){
    cnt += (A-B)/2 + (A-C)/2;
  }
  else if(B >= C && B >= A){
    cnt += (B-C)/2 + (B-A)/2;
  }
  else{
    cnt += (C-A)/2 + (C-B)/2;
  }
  cout << cnt << endl;
}