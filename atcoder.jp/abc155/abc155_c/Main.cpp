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
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i, N){
    cin >> S.at(i);
  }
  map<string, int> poll;
  rep(i, N){
    if(poll.count(S.at(i))){
      poll.at(S.at(i))++;
    }
    else{
      poll[S.at(i)] = 1;
    }
  }
  int m = 0;
  for(pair<string, int> x : poll){
    chmax(m, x.second);
  }
  vector<string> ans;
  for(pair<string, int> x : poll){
    if(x.second == m){
      ans.push_back(x.first);
    }
  }
  sort(all(ans));
  rep(i, sz(ans)){
    cout << ans.at(i) << endl;
  }
}