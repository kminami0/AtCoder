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

vector<ll> par;
vector<ll> rnk;
 
void init(ll n){
  rep(i, n){
    par.at(i) = i;
    rnk.at(i) = 1;
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
    rnk.at(y) += rnk.at(x);
  }
  else{
    par.at(y) = x;
    rnk.at(x) += rnk.at(y);
  }
}

struct edge {
  ll to;
  ll id;
  bool operator<(const edge &another) const{
    return id < another.id;
  };
};

int main(){
  ll N;
  cin >> N;
  par.resize(2*N);
  rnk.resize(2*N);
  init(2*N);
  vector<ll> A(N);
  rep(i, N){
    cin >> A.at(i);
    A.at(i)--;
    unite(i, A.at(i)+N);
    unite(i+N, A.at(i));
  }
  rep(i, N){
    if(same(i, i+N)){
      cout << -1 << endl;
      return 0;
    }
  }
  set<ll> r;
  rep(i, N){
    if(root(i) < N){
      r.insert(root(i));
    }
  }
  ll ans = 0;
  for(auto x : r){
    ans += (rnk.at(x)+1)/2;
  }
  cout << ans << endl;
}