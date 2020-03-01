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

int main(){
  vector<vector<ll>> A(3, vector<ll>(3, 0));
  rep(i, 3){
    rep(j, 3){
      cin >> A.at(i).at(j);
    }
  }
  ll N;
  cin >> N;
  vector<ll> b(N);
   set<ll> S;
  rep(i, N){
    cin >> b.at(i);
    S.insert(b.at(i));
  }
  bool bingo = false;
  bool out = false;
  rep(i, 3){
    rep(j, 3){
      if(!S.count(A.at(i).at(j))){
        break;
      }
      if(j == 2){
        bingo = true;
        break;
      }
    }
    if(bingo){
      break;
    }
  }
  rep(i, 3){
    rep(j, 3){
      if(!S.count(A.at(j).at(i))){
        break;
      }
      if(j == 2){
        bingo = true;
        break;
      }
    }
    if(bingo){
      break;
    }
  }
  rep(i, 3){
    if(!S.count(A.at(i).at(i))){
      break;
    }
    if(i == 2){
      bingo = true;
      break;
    }
  }
  rep(i, 3){
    if(!S.count(A.at(i).at(2-i))){
      break;
    }
    if(i == 2){
      bingo = true;
      break;
    }
  }
  if(bingo){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}