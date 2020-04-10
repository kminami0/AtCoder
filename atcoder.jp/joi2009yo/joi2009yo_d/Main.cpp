#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
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

ll m, n;
ll c;
vector<vector<ll>> a(90, vector<ll>(90, 0));

void dfs(ll x, ll y, ll b, set<pair<ll, ll>> S){
  if(x < 0 || n <= x){
    return;
  }
  if(y < 0 || m <= y){
    return;
  }
  if(a.at(x).at(y) == 0){
    return;
  }
  if(S.count(make_pair(x, y))){
    return;
  }
  S.insert(make_pair(x, y));
  chmax(c, b+1);
  dfs(x+1, y, b+1, S);
  dfs(x-1, y, b+1, S);
  dfs(x, y+1, b+1, S);
  dfs(x, y-1, b+1, S);
}

int main(){
  cin >> m >> n;
  rep(i, n){
    rep(j, m){
      cin >> a.at(i).at(j);
    }
  }
  rep(i, n){
    rep(j, m){
      if(a.at(i).at(j) == 1){
        set<pair<ll, ll>> S;
        dfs(i, j, 0, S);
      }
    }
  }
  cout << c << endl;
}