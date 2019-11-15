#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n){
    cin >> a.at(i);
  }
  int64_t cntp= 0;
  if(a.at(0) <= 0){
    cntp = -1 * a.at(0) + 1;
  }
  int sum = max(1, a.at(0));
  rep2(i, 1, n){
    if(sum > 0){
      if(sum + a.at(i) >= 0){
        cntp += sum + a.at(i) + 1;
        sum = -1;
      }
      else{
        sum += a.at(i);
      }
    }
    else{
      if(sum + a.at(i) <= 0){
        cntp += -1 * (sum + a.at(i)) + 1;
        sum = 1;
      }
      else{
        sum += a.at(i);
      }
    }
  }
  int64_t cntm= 0;
  if(a.at(0) >= 0){
    cntm = a.at(0) + 1;
  }
  int summ = min(-1, a.at(0));
  rep2(i, 1, n){
    if(summ > 0){
      if(summ + a.at(i) >= 0){
        cntm += summ + a.at(i) + 1;
        summ = -1;
      }
      else{
        summ += a.at(i);
      }
    }
    else{
      if(summ + a.at(i) <= 0){
        cntm += -1 * (summ + a.at(i)) + 1;
        summ = 1;
      }
      else{
        summ += a.at(i);
      }
    }
  }
  cout << min(cntp, cntm) << endl;
}