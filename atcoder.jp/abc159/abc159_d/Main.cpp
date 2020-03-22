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
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> c(N+1, 0);
  rep(i, N){
    cin >> A.at(i);
    c.at(A.at(i))++;
  }
  vector<ll> na(N+1, 0);
  vector<ll> ba(N+1, 0);
  vector<ll> da(N+1, 0);
  ll s = 0;
  rep(i, N){
    na.at(i+1) = c.at(i+1) * (c.at(i+1)-1) / 2;
    ba.at(i+1) = (c.at(i+1)-1) * (c.at(i+1)-2) / 2;
    da.at(i+1) = na.at(i+1) - ba.at(i+1);
    s += na.at(i+1);
  }
  rep(i, N){
    cout << s - da.at(A.at(i)) << endl;
  }
}