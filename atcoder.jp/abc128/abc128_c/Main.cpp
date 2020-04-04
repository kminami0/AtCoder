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

int main(){
  ll N, M;
  cin >> N >> M;
  vector<ll> k(M);
  vector<vector<ll>> s(M, vector<ll>(0));
  rep(i, M){
    cin >> k.at(i);
    rep(j, k.at(i)){
      ll a;
      cin >> a;
      a--;
      s.at(i).push_back(a);
    }
  }
  vector<ll> p(M);
  rep(i, M){
    cin >> p.at(i);
  }
  ll ans = 0;
  rep(i, 1<<N){
    rep(j, M){
      ll on = 0;
      rep(l, k.at(j)){
        if(i >> s.at(j).at(l) & 1){
          on++;
        }
      }
      if(on % 2 != p.at(j)){
        break;
      }
      if(j == M-1){
        ans++;
      }
    }
  }
  cout << ans << endl;
}