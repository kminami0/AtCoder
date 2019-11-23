#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int64_t N;
  cin >> N;
  vector<int64_t> A(N+1);
  A.at(0) = 0;
  rep(i, N){
    cin >> A.at(i+1);
  }
  long double len = 0;
  rep(i, N){
    len += A.at(i+1);
  }
  long double cen = len/2;
  int64_t tmp1 = 0;
  int64_t tmp2 = 0;
  int64_t pos = 0;
  while(tmp1 < cen){
    tmp1 += A.at(pos+1);
    tmp2 += A.at(pos);
    pos++;
  }
  if(tmp1 == cen){
    cout << 0 << endl;
  }
  else if(cen - tmp2 <= tmp1 - cen){
    cout << (int64_t)(2 * (cen - tmp2)) << endl;
  }
  else{
    cout << (int64_t)(2 * (tmp1 - cen)) << endl;
  }
}
