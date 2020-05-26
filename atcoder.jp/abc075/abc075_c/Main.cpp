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

vector<ll> par(100000);
vector<ll> rnk(100000);
 
void init(ll n){
  rep(i, n){
    par.at(i) = i;
    rnk.at(i) = 0;
  }
}
 
ll root(ll x){
  if(par.at(x) == x){
    return x;
  }
  else{
    par.at(x) = root(par.at(x));
    return par.at(x);
  }
}
 
bool same(ll x, ll y){
  if(root(x) == root(y)){
    return true;
  }
  else{
    return false;
  }
}
 
void unite(ll x, ll y){
  x = root(x);
  y = root(y);
  if(x == y){
    return;
  }
  if(rnk.at(x) < rnk.at(y)){
    par.at(x) = y;
  }
  else{
    par.at(y) = x;
    if(rnk.at(x) == rnk.at(y)){
      rnk.at(x)++;
    }
  }
}

int main(){
  ll N, M;
  cin >> N >> M;
  vector<ll> a(M), b(M);
  rep(i, M){
    cin >> a.at(i) >> b.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  ll ans = 0;
  rep(i, M){
    init(N);
    rep(j, M){
      if(j == i){
        continue;
      }
      unite(a.at(j), b.at(j));
    }
    rep(j, N-1){
      if(!same(0, j+1)){
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}