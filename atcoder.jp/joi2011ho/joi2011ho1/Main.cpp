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

int main(){
  ll M, N, K;
  cin >> M >> N >> K;
  vector<string> s(M);
  rep(i, M){
    cin >> s.at(i);
  }
  vector<ll> a(K), b(K), c(K), d(K);
  rep(i, K){
    cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
  }
  vector<vector<ll>> jn(M+1, vector<ll>(N+1, 0));
  vector<vector<ll>> o(M+1, vector<ll>(N+1, 0));
  vector<vector<ll>> ic(M+1, vector<ll>(N+1, 0));
  rep(i, M){
    rep(j, N){
      if(s.at(i).at(j) == 'J'){
        jn.at(i+1).at(j+1) = jn.at(i+1).at(j) + jn.at(i).at(j+1) - jn.at(i).at(j) + 1;
        o.at(i+1).at(j+1) = o.at(i+1).at(j) + o.at(i).at(j+1) - o.at(i).at(j);
        ic.at(i+1).at(j+1) = ic.at(i+1).at(j) + ic.at(i).at(j+1) - ic.at(i).at(j);
      }
      if(s.at(i).at(j) == 'O'){
        jn.at(i+1).at(j+1) = jn.at(i+1).at(j) + jn.at(i).at(j+1) - jn.at(i).at(j);
        o.at(i+1).at(j+1) = o.at(i+1).at(j) + o.at(i).at(j+1) - o.at(i).at(j) + 1;
        ic.at(i+1).at(j+1) = ic.at(i+1).at(j) + ic.at(i).at(j+1) - ic.at(i).at(j);
      }
      if(s.at(i).at(j) == 'I'){
        jn.at(i+1).at(j+1) = jn.at(i+1).at(j) + jn.at(i).at(j+1) - jn.at(i).at(j);
        o.at(i+1).at(j+1) = o.at(i+1).at(j) + o.at(i).at(j+1) - o.at(i).at(j);
        ic.at(i+1).at(j+1) = ic.at(i+1).at(j) + ic.at(i).at(j+1) - ic.at(i).at(j) + 1;
      }
    }
  }
  rep(j, K){
    cout << jn.at(c.at(j)).at(d.at(j)) - jn.at(c.at(j)).at(b.at(j)-1) - jn.at(a.at(j)-1).at(d.at(j)) + jn.at(a.at(j)-1).at(b.at(j)-1) << " ";
    cout << o.at(c.at(j)).at(d.at(j)) - o.at(c.at(j)).at(b.at(j)-1) - o.at(a.at(j)-1).at(d.at(j)) + o.at(a.at(j)-1).at(b.at(j)-1) << " ";
    cout << ic.at(c.at(j)).at(d.at(j)) - ic.at(c.at(j)).at(b.at(j)-1) - ic.at(a.at(j)-1).at(d.at(j)) + ic.at(a.at(j)-1).at(b.at(j)-1) << endl;
  }
}