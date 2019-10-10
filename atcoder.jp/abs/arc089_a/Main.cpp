#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool travel(int time, int cx, int cy, int fx, int fy){
  if(abs(fx-cx)+abs(fy-cy) <= time && time % 2 == (abs(fx-cx)+abs(fy-cy)) % 2){
    return true;
  }
  else{
    return false;
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> t(N+1), x(N+1), y(N+1);
  t.at(0) = 0;
  x.at(0) = 0;
  y.at(0) = 0;
  rep(i, N){
    cin >> t.at(i+1) >> x.at(i+1) >> y.at(i+1);
  }
  rep(i, N){
    if(!(travel(t.at(i+1)-t.at(i), x.at(i), y.at(i), x.at(i+1), y.at(i+1)))){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
