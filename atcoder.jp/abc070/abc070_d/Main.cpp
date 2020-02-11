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
  int to;
  int id;
  ll dst;
  bool operator<(const edge &another) const{
    return id < another.id;
  };
};

vector<pair<int, vector<edge>>> tree;

int main(){
  int N;
  cin >> N;
  tree.resize(N);
  vector<int> a(N-1), b(N-1);
  vector<ll> c(N-1);
  rep(i, N-1){
    cin >> a.at(i) >> b.at(i) >> c.at(i);
    a.at(i)--;
    b.at(i)--;
    tree.at(a.at(i)).first = a.at(i);
    tree.at(b.at(i)).first = b.at(i);
    tree.at(a.at(i)).second.push_back({ b.at(i), i, c.at(i) });
    tree.at(b.at(i)).second.push_back({ a.at(i), i, c.at(i) });
  }
  vector<ll> d(N, 200000000900000);
  int Q, K;
  cin >> Q >> K;
  d.at(K-1) = 0;
  vector<int> x(Q), y(Q);
  rep(i, Q){
    cin >> x.at(i) >> y.at(i);
    x.at(i)--;
    y.at(i)--;
  }
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push(make_pair(0, K-1));
  while(!pq.empty()){
    int v = pq.top().second;
    int ds = pq.top().first;
    pq.pop();
    rep(i, sz(tree.at(v).second)) {
      if(chmin(d.at(tree.at(v).second.at(i).to), d.at(v)+tree.at(v).second.at(i).dst)){
        pq.push(make_pair(d.at(tree.at(v).second.at(i).to), tree.at(v).second.at(i).to));
      }
    }
  }
  rep(i, Q){
    cout << d.at(x.at(i)) + d.at(y.at(i)) << endl;
  }
}