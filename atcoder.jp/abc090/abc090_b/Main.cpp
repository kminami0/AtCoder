#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int A, B;
  cin >> A >> B;
  int cnt = 0;
  rep2(i, A, B+1){
    string s = to_string(i);
    string t = to_string(i);
    reverse(all(t));
    if(s == t){
      cnt++;
    }
  }
  cout << cnt << endl;
}