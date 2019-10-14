#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int gcd(int a, int b){
  int x = abs(a);
  int y = abs(b);
  int z = 0;
  
  try{
    if(x == 0 && y == 0){
      throw "gcd(0,0) is infinity.";
    }
  }
  catch(string s){
    cout << s << endl;
    return 1;
  }
  
  if(x >= y){
    if(y == 0){
      return x;
    }
    else{
      z = y;
      y = x % y;
      x = z;
      return gcd(x, y);
    }
  }
  else{
    if(x == 0){
      return y;
    }
    else{
      z = x;
      x = y % x;
      y = z;
      return gcd(x, y);
    }
  }
}
 
int main(){
  int A, B, C;
  cin >> A >> B >> C;
  int res = A % B;
  if(C % gcd(res, B) == 0){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}