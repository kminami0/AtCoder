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

ll N, M, Q, ans;
vector<ll> a, b, c, d;

void dfs(vector<ll> A){
  if(sz(A) == N+1){
    ll y = 0;
    rep(i, Q){
      if(A.at(b.at(i)) - A.at(a.at(i)) == c.at(i)){
        y += d.at(i);
      }
    }
    chmax(ans, y);
    return;
  }
  ll x = A.back();
  while(x <= M){
    A.push_back(x);
    dfs(A);
    A.pop_back();
    x++;
  }
}

int main(){
  cin >> N >> M >> Q;
  a.resize(Q);
  b.resize(Q);
  c.resize(Q);
  d.resize(Q);
  rep(i, Q){
    cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
  }
  dfs(vector<ll>(1,1));
  cout << ans << endl;
}