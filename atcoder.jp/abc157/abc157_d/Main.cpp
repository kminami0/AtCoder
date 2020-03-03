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

int main(){
  ll N, M, K;
  cin >> N >> M >> K;
  init(N);
  vector<ll> A(M), B(M), C(K), D(K);
  vector<set<ll>> F(N);
  rep(i, M){
    cin >> A.at(i) >> B.at(i);
    A.at(i)--;
    B.at(i)--;
    unite(A.at(i), B.at(i));
    F.at(A.at(i)).insert(B.at(i));
    F.at(B.at(i)).insert(A.at(i));
  }
  vector<set<ll>> bl(N);
  rep(i, K){
    cin >> C.at(i) >> D.at(i);
    C.at(i)--;
    D.at(i)--;
    bl.at(C.at(i)).insert(D.at(i));
    bl.at(D.at(i)).insert(C.at(i));
  }
  vector<ll> ans(N, 0);
  vector<ll> bf(N);
  rep(i, N){
    for(auto j : bl.at(i)){
      if(same(i, j)){
        bf.at(i)++;
      }
    }
    ans.at(i) = rnk.at(root(i)) - sz(F.at(i)) - 1 - bf.at(i);
  }
  rep(i, N){
    cout << ans.at(i) << " ";
  }
}