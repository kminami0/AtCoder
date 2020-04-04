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
  ll R, C;
  cin >> R >> C;
  vector<vector<ll>> a(R, vector<ll>(C));
  rep(i, R){
    rep(j, C){
      cin >> a.at(i).at(j);
    }
  }
  ll ans = 0;
  rep(i, 1<<R){
    ll g = 0;
    vector<vector<ll>> b(R, vector<ll>(C));
    rep(j, R){
      rep(k, C){
        b.at(j).at(k) = a.at(j).at(k);
      }
    }
    rep(j, R){
      if(i >> j & 1){
        rep(k, C){
          b.at(j).at(k) = 1 - b.at(j).at(k);
        }
      }
    }
    rep(j, C){
      ll c0 = 0;
      ll c1 = 0;
      rep(k, R){
        if(b.at(k).at(j) == 0){
          c0++;
        }
        else{
          c1++;
        }
      }
      g += max(c0, c1);
    }
    chmax(ans, g);
  }
  cout << ans << endl;
}