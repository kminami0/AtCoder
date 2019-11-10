#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  vector<vector<int>> c(3, vector<int>(3, 0));
  rep(i, 3){
    rep(j, 3){
      cin >> c.at(i).at(j);
    }
  }
  rep(a0, 101){
    rep(a1, 101){
      rep(a2, 101){
        if(c.at(0).at(0) - a0 == c.at(1).at(0) - a1 &&
           c.at(1).at(0) - a1 == c.at(2).at(0) - a2 &&
           c.at(0).at(1) - a0 == c.at(1).at(1) - a1 &&
           c.at(1).at(1) - a1 == c.at(2).at(1) - a2 &&
           c.at(0).at(2) - a0 == c.at(1).at(2) - a1 &&
           c.at(1).at(2) - a1 == c.at(2).at(2) - a2){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}