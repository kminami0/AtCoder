#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000000
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

vector<vector<P>> dp(1001, vector<P>(1001));
//dp.at(i).at(j)は左の山からi個取って、右の山からj個取った状態からゲームを始めたときに
//すぬけ君とすめけ君がそれぞれ取るものの価値の合計のペア

int main(){
  int A, B;
  cin >> A >> B;
  vector<int> a(A), b(B);
  rep(i, A){
    cin >> a.at(i);
  }
  rep(i, B){
    cin >> b.at(i);
  }
  rep(i, A+1){
    rep(j, B+1){
      if(i >= 1 && j >= 1){
        if(dp.at(A-i+1).at(B-j).second + a.at(A-i) > dp.at(A-i).at(B-j+1).second + b.at(B-j)){
          dp.at(A-i).at(B-j).first = dp.at(A-i+1).at(B-j).second + a.at(A-i);
          dp.at(A-i).at(B-j).second = dp.at(A-i+1).at(B-j).first;
        }
        else{
          dp.at(A-i).at(B-j).first = dp.at(A-i).at(B-j+1).second + b.at(B-j);
          dp.at(A-i).at(B-j).second = dp.at(A-i).at(B-j+1).first;
        }
      }
      else if(i >= 1){
        dp.at(A-i).at(B).first = dp.at(A-i+1).at(B).second + a.at(A-i);
        dp.at(A-i).at(B).second = dp.at(A-i+1).at(B).first;
      }
      else if(j >= 1){
        dp.at(A).at(B-j).first = dp.at(A).at(B-j+1).second + b.at(B-j);
        dp.at(A).at(B-j).second = dp.at(A).at(B-j+1).first;
      }
    }
  }
  cout << dp.at(0).at(0).first << endl;
}