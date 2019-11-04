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
  vector<int> x(N), y(N);
  rep(i, N){
    cin >> x.at(i) >> y.at(i);
  }
  double len = 0;
  rep(i, N){
    rep(j, N){
      chmax(len, (pow(x.at(i)-x.at(j), 2) + pow(y.at(i)-y.at(j), 2)));
    }
  }
  cout << fixed << setprecision(6);
  cout << pow(len, 0.5) << endl;
}