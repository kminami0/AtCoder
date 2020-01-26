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

int main(){
  ll N;
  cin >> N;
  vector<P> R(N), B(N);
  rep(i, N){
    cin >> R.at(i).first >> R.at(i).second;
  }
  rep(i, N){
    cin >> B.at(i).first >> B.at(i).second;
  }
  sort(all(R));
  sort(all(B));
  vector<bool> used(N, false);
  ll cnt = 0;
  P tmp = make_pair(-1, -1);
  rep(i, N){
    rep(j, N){
      if(R.at(j).first < B.at(i).first && R.at(j).second < B.at(i).second && !used.at(j)){
        if(chmax(tmp.second, R.at(j).second)){
          tmp.first = j;
        }
      }
    }
    if(tmp.first != -1){
      used.at(tmp.first) = true;
      cnt++;
    }
    tmp.first = -1;
    tmp.second = -1;
  }
  cout << cnt << endl;
}