#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> a(M);
  vector<int> b(M);
  rep(i, M){
    cin >> a.at(i) >> b.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  vector<int> cnt(N);
  rep(i, M){
    cnt.at(a.at(i))++;
    cnt.at(b.at(i))++;
  }
  rep(i, N){
    cout << cnt.at(i) << endl;
  }
}