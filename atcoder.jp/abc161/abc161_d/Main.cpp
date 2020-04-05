#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000099
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

ll countlunlun(string x){ // x以下のルンルン数の個数
  vector<vector<vector<vector<ll>>>> dp(20, vector<vector<vector<ll>>>(2, vector<vector<ll>>(10, vector<ll>(2, 0))));
  rep(i, sz(x)){
    if(i == 0){
      rep(d, (x.at(i)-'0')+1){
        if(d == 0){
          dp.at(i+1).at(1).at(d).at(0) = 1;
        }
        else if(d < x.at(i)-'0'){
          dp.at(i+1).at(1).at(d).at(1) = 1;
        }
        else{
          dp.at(i+1).at(0).at(d).at(1) = 1;
        }
      }
    }
    else{
      rep(j, 2){
        rep(d, (j ? 9 : x.at(i)-'0')+1){
          if(d == 0){
            dp.at(i+1).at(j || ( d < x.at(i)-'0' )).at(d).at(0) += dp.at(i).at(j).at(0).at(0);
            dp.at(i+1).at(j || ( d < x.at(i)-'0' )).at(d).at(1) += dp.at(i).at(j).at(1).at(1) + dp.at(i).at(j).at(0).at(1);
          }
          else if(d == 9){
            dp.at(i+1).at(j || ( d < x.at(i)-'0' )).at(d).at(1) += dp.at(i).at(j).at(0).at(0) + dp.at(i).at(j).at(8).at(1) + dp.at(i).at(j).at(9).at(1);
          }
          else{
            dp.at(i+1).at(j || ( d < x.at(i)-'0' )).at(d).at(1) += dp.at(i).at(j).at(0).at(0) + dp.at(i).at(j).at(d+1).at(1) + dp.at(i).at(j).at(d-1).at(1) + dp.at(i).at(j).at(d).at(1);
          }
        }
      }
    }
  }
  ll sum = 0;
  rep(d, 10){
    sum += dp.at(sz(x)).at(1).at(d).at(1) + dp.at(sz(x)).at(0).at(d).at(1);
  }
  return sum;
}

int main(){
  ll K;
  cin >> K;
  ll l = 0;
  ll r = INF;
//  cout << countlunlun(to_string(21)) << endl;
//  cout << countlunlun(to_string(102)) << endl;
  while(r-l > 1){
//    cout << (l+r)/2 << " " << countlunlun(to_string((l+r)/2))<<  "ko" << endl;
    if(countlunlun(to_string((l+r)/2)) < K){
      l = (l+r)/2;
    }
    else{
      r = (l+r)/2;
    }
//    cout << l << " " << r << endl;
  }
  cout << r << endl;
}