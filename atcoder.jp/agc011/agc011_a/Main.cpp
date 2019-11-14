#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> T(N);
  rep(i, N){
    cin >> T.at(i);
  }
  sort(all(T));
  int cus = 1;
  int i = 0;
  int j = 1;
  int bus = 1;
  while(i < N){
    while(i+j < N){
      if(T.at(i+j) - T.at(i) <= K){
        if(cus < C){
          cus++;
        }
        else{
          bus++;
          cus = 1;
          break;
        }
      }
      else{
        bus++;
        cus = 1;
        break;
      }
      if(i+j == N-1){
        cout << bus << endl;
        return 0;
      }
      j++;
    }
    i = i+j;
    j = 1;
  }
  cout << bus << endl;
}