#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  string s;
  cin >> s;
  vector<int> A(4);
  rep(i, 4){
    A.at(i) = s.at(i) - '0';
  }
  if(A.at(0) + A.at(1) + A.at(2) + A.at(3) == 7){
    cout << s.at(0) << '+' << s.at(1) << '+' << s.at(2) << '+' << s.at(3)<< "=7" << endl;
    return 0;
  }
  else if(A.at(0) + A.at(1) + A.at(2) - A.at(3) == 7){
    cout << s.at(0) << '+' << s.at(1) << '+' << s.at(2) << '-' << s.at(3)<< "=7" << endl;
    return 0;
  }
  else if(A.at(0) + A.at(1) - A.at(2) + A.at(3) == 7){
    cout << s.at(0) << '+' << s.at(1) << '-' << s.at(2) << '+' << s.at(3)<< "=7" << endl;
    return 0;
  }
  else if(A.at(0) + A.at(1) - A.at(2) - A.at(3) == 7){
    cout << s.at(0) << '+' << s.at(1) << '-' << s.at(2) << '-' << s.at(3)<< "=7" << endl;
    return 0;
  }
  else if(A.at(0) - A.at(1) + A.at(2) + A.at(3) == 7){
    cout << s.at(0) << '-' << s.at(1) << '+' << s.at(2) << '+' << s.at(3)<< "=7" << endl;
    return 0;
  }
  else if(A.at(0) - A.at(1) + A.at(2) - A.at(3) == 7){
    cout << s.at(0) << '-' << s.at(1) << '+' << s.at(2) << '-' << s.at(3)<< "=7" << endl;
    return 0;
  }
  else if(A.at(0) - A.at(1) - A.at(2) + A.at(3) == 7){
    cout << s.at(0) << '-' << s.at(1) << '-' << s.at(2) << '+' << s.at(3)<< "=7" << endl;
    return 0;
  }
  else if(A.at(0) - A.at(1) - A.at(2) - A.at(3) == 7){
    cout << s.at(0) << '-' << s.at(1) << '-' << s.at(2) << '-' << s.at(3)<< "=7" << endl;
    return 0;
  }
}