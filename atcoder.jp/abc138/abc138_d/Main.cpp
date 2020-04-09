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

struct edge {
  ll to;
  ll id;
  bool operator<(const edge &another) const{
    return id < another.id;
  };
};

vector<pair<int, vector<edge>>> tree;
vector<ll> d;
queue<ll> det;
ll dc = 0;

void bfs(ll x, ll i){
  if(d.at(x) >= 0){
    return;
  }
  d.at(x) = i;
  dc++;
  det.push(x);
}

vector<ll> addv;

void dfs(ll x, ll y){
  y += addv.at(x);
  tree.at(x).first += y;
  for(auto e : tree.at(x).second){
    if(d.at(e.to) > d.at(x)){
      dfs(e.to, y);
    }
  }
}

int main(){
  ll N, Q;
  cin >> N >> Q;
  d.resize(N);
  tree.resize(N);
  addv.resize(N);
  rep(i, N){
    d.at(i) = -1;
    addv.at(i) = 0;
  }
  vector<ll> a(N-1), b(N-1), p(Q), x(Q);
  rep(i, N-1){
    cin >> a.at(i) >> b.at(i);
    a.at(i)--;
    b.at(i)--;
    tree.at(a.at(i)).first = 0;
    tree.at(b.at(i)).first = 0;
    tree.at(a.at(i)).second.push_back({ b.at(i), i });
    tree.at(b.at(i)).second.push_back({ a.at(i), i });
  }
  rep(i, Q){
    cin >> p.at(i) >> x.at(i);
    p.at(i)--;
    addv.at(p.at(i)) += x.at(i);
  }
  bfs(0, 0);
  while(dc != N){
    ll q = det.front();
    det.pop();
    for(auto e : tree.at(q).second){
      bfs(e.to, d.at(q)+1);
    }
  }
  dfs(0, 0);
  rep(i, N){
    cout << tree.at(i).first << " ";
  }
  cout << endl;
}