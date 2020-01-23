#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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

int main(){
  int N;
  cin >> N;
  vector<ll> w(N);
  rep(i, N){
    cin >> w.at(i);
  }
  vector<ll> put(0);
  bool hv = true;
  int pos = 0;
  ll tmp = INF;
  rep(i, N){
    rep(j, sz(put)){
      if(w.at(i) <= put.at(j)){
        break;
      }
      if(j == sz(put)-1){
        hv = true;
      }
    }
    if(hv){
      put.push_back(w.at(i));
      hv = false;
    }
    else{
      rep(j, sz(put)){
        if(w.at(i) <= put.at(j)){
          if(chmin(tmp, put.at(j))){
            pos = j;
          }
        }
      }
      put.at(pos) = w.at(i);
      tmp = INF;
    }
  }
  cout << sz(put) << endl;
}