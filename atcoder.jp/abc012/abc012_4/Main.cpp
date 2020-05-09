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

struct edge{
  ll to;
  ll time;
};

vector<vector<edge>> graph;

int main(){
  ll N, M;
  cin >> N >> M;
  graph.resize(N);
  vector<ll> a(M), b(M), t(M);
  vector<vector<ll>> d(N, vector<ll>(N, INF));
  rep(i, N){
    d.at(i).at(i) = 0;
  }
  rep(i, M){
    cin >> a.at(i) >> b.at(i) >> t.at(i);
    a.at(i)--;
    b.at(i)--;
    graph.at(a.at(i)).push_back({b.at(i), t.at(i)});
    graph.at(b.at(i)).push_back({a.at(i), t.at(i)});
    d.at(a.at(i)).at(b.at(i)) = t.at(i);
    d.at(b.at(i)).at(a.at(i)) = t.at(i);
  }
  rep(k, N){
    rep(i, N){
      rep(j, N){
        chmin(d.at(i).at(j), d.at(i).at(k)+d.at(k).at(j));
      }
    }
  }
  priority_queue<pair<ll, ll>> S;
  rep(i, N){
    rep(j, N){
      S.push(make_pair(d.at(i).at(j), i));
    }
  }
  set<ll> T;
  while(sz(T) != N-1){
    ll s = S.top().second;
    S.pop();
    T.insert(s);
  }
  ll x = 0;
  rep(i, N){
    if(!T.count(i)){
      x = i;
      break;
    }
  }
  ll ans = 0;
  rep(i, N){
    chmax(ans, d.at(x).at(i));
  }
  cout << ans << endl;
}