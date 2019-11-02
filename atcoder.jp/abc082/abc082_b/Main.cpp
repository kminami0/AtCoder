#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)

int main(){
  string s, t;
  cin >> s >> t;
  sort(all(s));
  sort(all(t));
  reverse(all(t));
  if(s.compare(t) < 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}