#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string S;
  cin >> S;
  vector<string> d = {"maerd", "remaerd", "esare", "resare"};
  reverse(S.begin(), S.end());
  
  int i=0;
  
  while(i < S.size()){
    rep(j, 4){
      if(S.substr(i, d.at(j).size()) == d.at(j)){
        i += d.at(j).size();
        break;
      }
      if(j == 3){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
}
