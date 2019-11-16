#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  if(N % 2 == 1){
    cout << "No" << endl;
  }
  else{
    vector<char> S1(N/2);
    rep(i, N/2){
      S1.at(i) = S.at(i);
    }
    rep(i, N/2){
      if(S.at(N/2 +i) != S1.at(i)){
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
  }
}