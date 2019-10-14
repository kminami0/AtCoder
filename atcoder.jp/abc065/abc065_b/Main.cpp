#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N){
    cin >> a.at(i);
  }
  int cnt = 0;
  vector<bool> pushed(N, false);
  int light = 0;
  
  while(light != 1){
    if(pushed.at(light) == true){
      cnt = -1;
      break;
    }
    else{
      pushed.at(light) = true;
      light = a.at(light)-1;
      cnt++;
    }
  }
  
  cout << cnt << endl;
}