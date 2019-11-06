#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  string S;
  cin >> S;
  sort(all(S));
  char alp = 'a';
  rep(i, S.size()){
    if(S.at(i) == alp){
      alp++;
    }
    else if(S.at(i) > alp){
      cout << alp << endl;
      return 0;
    }
  }
  if(S.at(S.size()-1) == 'z'){
    cout << "None" << endl;
  }
  else{
    cout << alp << endl;
  }
}
