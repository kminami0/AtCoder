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
  vector<int> A(N);
  rep(i, N){
    cin >> A.at(i);
  }
  int Max = A.at(0);
  int Min = A.at(0);
  rep(i, N){
    if(A.at(i) > Max){
      chmax(Max, A.at(i));
    }
    else if(A.at(i) < Min){
      chmin(Min, A.at(i));
    }
  }
  cout << Max - Min << endl;
}