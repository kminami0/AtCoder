#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000009
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

vector<vector<ll>> dp(2002, vector<ll>(2002));
//dp.at(i).at(j)はXがi番目、Yがj番目のカードを持っているときから
//開始したときのスコア
//i<j ならXの手番から、j<i ならYの手番から

int main(){
  int N;
  ll Z, W;
  cin >> N >> Z >> W;
  vector<ll> a(N+2);
  a.at(0) = Z;
  a.at(1) = W;
  rep(i, N){
    cin >> a.at(i+2);
  }
  rep(i, N+1){
    dp.at(N+1).at(i) = abs(a.at(N+1) - a.at(i));
    dp.at(i).at(N+1) = abs(a.at(N+1) - a.at(i));
  }
  bool ch = false;
  vector<int> bestX(N+2, -1); 
  //bestX.at(i)はXの手番でYがi番目のカードを持っているときに何番目のカードを手にすべきか
  vector<int> bestY(N+2, -1);
  rep(i, N+2){
    rep(j, N+1){
      if(i == j){
        continue;
      }
      else if(i > j){ // Xの手番
        if(bestX.at(N+1-j) >= 0){
          dp.at(N+1-i).at(N+1-j) = dp.at(bestX.at(N+1-j)).at(N+1-j);
          continue;
        }
        ll a = -1;
        rep2(k, 1, j+1){
          if(chmax(a, dp.at(N+1-j+k).at(N+1-j))){
            bestX.at(N+1-j) = N+1-j+k;
          }
          ch = true;
        }
        if(ch){
          dp.at(N+1-i).at(N+1-j) = a;
        }
        ch = false;
      }
      else{
        if(bestY.at(N+1-i) >= 0){
          dp.at(N+1-i).at(N+1-j) = dp.at(N+1-i).at(bestY.at(N+1-i));
          continue;
        }
        ll b = INF;
        rep2(k, 1, i+1){
          if(chmin(b, dp.at(N+1-i).at(N+1-i+k))){
            bestY.at(N+1-i) = N+1-i+k;
          }
          ch = true;
        }
        if(ch){
          dp.at(N+1-i).at(N+1-j) = b;
        }
        ch = false;
      }
    }
  }
  cout << dp.at(0).at(1) << endl;
}