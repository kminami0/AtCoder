#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

bool IsPrime(int64_t i){
  int64_t j = 2;
  while(j * j <= i){
    if(i % j == 0){
      return false;
    }
    j++;
  }
  return true;
}

int main(){
  int64_t N, K, R, S, P;
  string T;
  cin >> N >> K >> R >> S >> P >> T;
  int64_t ans = 0;
  vector<bool> chg(N, false);
  rep(i, sz(T)){
    if(i < K){
      if(T.at(i) == 'r'){
        ans += P;
      }
      else if(T.at(i) == 's'){
        ans += R;
      }
      else{
        ans += S;
      }
    }
    else{
      if(T.at(i) != T.at(i-K)){
        if(T.at(i) == 'r'){
          ans += P;
        }
        else if(T.at(i) == 's'){
          ans += R;
        }
        else{
          ans += S;
        }
      }
      else{
        if(chg.at(i-K)){
          if(T.at(i) == 'r'){
            ans += P;
          }
          else if(T.at(i) == 's'){
            ans += R;
          }
          else{
            ans += S;
          }
        }
        else{
          chg.at(i) = true;
        }
      }
    }
  }
  cout << ans << endl;
}