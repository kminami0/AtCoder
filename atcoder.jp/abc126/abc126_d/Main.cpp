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

struct edge {
  ll to;
  ll id;
  bool operator<(const edge &another) const{
    return id < another.id;
  };
  ll length;
};

vector<pair<int, vector<edge>>> tree;
vector<bool> p(false);
vector<bool> color(false);

void dfs(ll x, ll d){
  if(p.at(x)){
    return;
  }
  p.at(x) = true;
  if(d % 2 == 0){
    color.at(x) = true;
  }
  for(auto e : tree.at(x).second){
    dfs(e.to, d+e.length);
  }
}

int main(){
  ll N;
  cin >> N;
  tree.resize(N);
  p.resize(N);
  color.resize(N);
  vector<ll> u(N-1), v(N-1), w(N-1);
  rep(i, N-1){
    cin >> u.at(i) >> v.at(i) >> w.at(i);
    u.at(i)--;
    v.at(i)--;
    tree.at(u.at(i)).first = u.at(i);
    tree.at(v.at(i)).first = v.at(i);
    tree.at(u.at(i)).second.push_back({ v.at(i), i, w.at(i) });
    tree.at(v.at(i)).second.push_back({ u.at(i), i, w.at(i) });
  }
  color.at(0) = true;
  dfs(0, 0);
  rep(i, N){
    if(color.at(i)){
      cout << 0 << endl;
    }
    else{
      cout << 1 << endl;
    }
  }
}