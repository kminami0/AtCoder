#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main(){
  int64_t N;
  cin >> N;
  int64_t cnt = N-1;
  vector<int64_t> div1(floor(sqrt(N))+1,0);
  vector<int64_t> div2(floor(sqrt(N))+1,0);
  int64_t j = 0;
  
  rep2(i, 1, floor(sqrt(N))+1){
    if(N % i == 0){
      div1.at(j) = i;
      div2.at(j) = N / i;
      j++;
    }
  }
  j = 0;
  
  while(div1.at(j) != 0){
    if(div1.at(j) + div2.at(j) -2 < cnt){
      cnt = div1.at(j) + div2.at(j) -2;
    }
    j++;
  }
  
  cout << cnt << endl;
}