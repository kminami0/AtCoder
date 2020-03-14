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

vector<ll> par(100000);
vector<ll> rnk(100000);
vector<ll> diff_weight(100000);
 
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
    ll r = root(par.at(x));
    diff_weight.at(x) += diff_weight.at(par.at(x));
    return par.at(x) = r;
  }
}

ll weight(ll x){
  root(x);
  return diff_weight.at(x);
}

ll diff(ll x, ll y){
  return weight(y) - weight(x);
}
 
bool same(ll x, ll y){
  if(root(x) == root(y)){
    return true;
  }
  else{
    return false;
  }
}
 
bool unite(ll x, ll y, ll w){
  w += weight(x); w -= weight(y); 
  x = root(x);
  y = root(y);
  if(x == y){
    return false;
  }
  if(rnk.at(x) < rnk.at(y)){
    swap(x, y);
    w = -w;
  }
  if(rnk.at(x) == rnk.at(y)){
    rnk.at(x)++;
  }
  par.at(y) = x;
  diff_weight.at(y) = w; 
  return true;
}

int main(){
  ll N, M;
  cin >> N >> M;
  init(N);
  vector<ll> L(M), R(M), D(M);
  rep(i, M){
    cin >> L.at(i) >> R.at(i) >> D.at(i);
    L.at(i)--;
    R.at(i)--;
    if(!same(L.at(i), R.at(i))){
      unite(L.at(i), R.at(i), D.at(i));
    }
    else if(diff(L.at(i), R.at(i)) != D.at(i)){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}