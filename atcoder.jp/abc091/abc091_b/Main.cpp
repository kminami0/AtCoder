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
  vector<string> s(N);
  rep(i, N){
    cin >> s.at(i);
  }
  int M;
  cin >> M;
  vector<string> t(M);
  rep(i, M){
    cin >> t.at(i);
  }
  map<string, int> money;
  rep(i, N){
    money[s.at(i)]++;
  }
  rep(i, M){
    money[t.at(i)]--;
  }
  int score = 0;
  rep(i, N){
    chmax(score, money.at(s.at(i)));
  }
  cout << score << endl;
}