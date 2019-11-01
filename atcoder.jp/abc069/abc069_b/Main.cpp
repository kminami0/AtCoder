#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)

int main(){
  string s;
  cin >> s;
  string t = s.at(0) + to_string(s.size()-2) + s.at(s.size()-1);
  cout << t << endl;
}