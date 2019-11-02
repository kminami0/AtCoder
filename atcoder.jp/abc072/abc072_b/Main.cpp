#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  string s;
  cin >> s;
  string t = "";
  int i = 0;
  while(i < s.size()){
    t += s.at(i);
    i += 2;
  }
  cout << t << endl;
}