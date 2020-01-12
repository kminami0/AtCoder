#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
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
  int N, M;
  cin >> N >> M;
  vector<int> p(M);
  vector<string> S(M);
  rep(i, M){
    cin >> p.at(i) >> S.at(i);
    p.at(i)--;
  }
  vector<pair<bool, int>> res(N);
  rep(i, N){
    res.at(i) = make_pair(false, 0);
  }
  rep(i, M){
    if(S.at(i) == "AC"){
      res.at(p.at(i)).first = true;
    }
    else if(!res.at(p.at(i)).first){
      res.at(p.at(i)).second++;
    }
  }
  int ac = 0;
  int pn = 0;
  rep(i, N){
    if(res.at(i).first){
      ac++;
      pn += res.at(i).second;
    }
  }
  cout << ac << " " << pn << endl;
}