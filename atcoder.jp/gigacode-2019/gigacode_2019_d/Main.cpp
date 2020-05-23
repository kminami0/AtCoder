#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14 100兆
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
  ll H, W, K, V;
  cin >> H >> W >> K >> V;
  vector<vector<ll>> A(H, vector<ll>(W));
  rep(i, H){
    rep(j, W){
      cin >> A.at(i).at(j);
    }
  }
  vector<vector<ll>> s(H+1, vector<ll>(W+1, 0));
  rep(i, H){
    rep(j, W){
      s.at(i+1).at(j+1) = s.at(i+1).at(j) + s.at(i).at(j+1) - s.at(i).at(j) + A.at(i).at(j);
    }
  }
  ll ans = 0;
  rep(i, H){
    rep(j, W){
      rep2(k, i, H){
        rep2(l, j, W){
          ll cost = s.at(k+1).at(l+1) - s.at(k+1).at(j) - s.at(i).at(l+1) + s.at(i).at(j) + (k-i+1)*(l-j+1)*K;
          if(cost <= V){
            chmax(ans, (k-i+1)*(l-j+1));
          }
        }
      }
    }
  }
  cout << ans << endl;
}