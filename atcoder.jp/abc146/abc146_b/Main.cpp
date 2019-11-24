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
  rep(i, S.size()){
    if(S.at(i) + N <= 'Z'){
      S.at(i) += N;
    }
    else{
      S.at(i) += N;
      S.at(i) -= 26;
    }
  }
  cout << S << endl;
}