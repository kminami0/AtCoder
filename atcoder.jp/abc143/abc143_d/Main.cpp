#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(){
  int N = 0;
  cin >> N;
  vector<int> L(N);
  rep(i, N){
    cin >> L.at(i);
  }
  vector<int> b(1001, 0);
  rep(i, N){
    b.at(L.at(i))++;
  }
  int64_t cnt = 0;
  int64_t temp1, temp2, temp3 = 0;
  rep(i, 1001){
    if(b.at(i) > 0){
      temp1 = b.at(i);
      b.at(i)--;
      rep2(j, i, 1001){
        if(b.at(j) > 0){
          temp2 = b.at(j);
          b.at(j)--;
          rep2(k, j, 1001){
            if(b.at(k) > 0){
              temp3 = b.at(k);
              if(i < j+k && j < k+i && k < i+j){
                if(i == j && j == k){
                  cnt += temp1 * temp2 * temp3 / 6;
                }
                else if(i == j || j == k || k == i){
                  cnt += temp1 * temp2 * temp3 / 2;
                }
                else{
                cnt += temp1 * temp2 * temp3;
                }
              }
            }
          }
          b.at(j)++;
        }
        
      }
      b.at(i)++;
    }
  }
  
  cout << cnt << endl;
}