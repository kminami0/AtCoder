#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int N, T, A;
  cin >> N >> T >> A;
  vector<int> H(N);
  rep(i, N){
    cin >> H.at(i);
  }
  double diff = abs(T - H.at(0) * 0.006 - A);
  int p = 0;
  rep(i, N){
    if(diff > abs(T - H.at(i) * 0.006 - A)){
      chmin(diff, abs(T - H.at(i) * 0.006 - A));
      p = i;
    }
  }
  cout << p+1 << endl;
}