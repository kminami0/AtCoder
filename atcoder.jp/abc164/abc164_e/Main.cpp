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

struct edge {
  ll to;
  ll money;
  ll time;
};

vector<pair<int, vector<edge>>> graph;
vector<vector<ll>> dp(50, vector<ll>(2451, INF));
//dp.at(i).at(j)は都市iに所持金jで到達するための最小時間

int main(){
  ll N, M, S;
  cin >> N >> M >> S;
  graph.resize(N);
  vector<ll> U(M), V(M), A(M), B(M);
  rep(i, M){
    cin >> U.at(i) >> V.at(i) >> A.at(i) >> B.at(i);
    U.at(i)--;
    V.at(i)--;
    graph.at(U.at(i)).first = U.at(i);
    graph.at(V.at(i)).first = V.at(i);
    graph.at(U.at(i)).second.push_back({V.at(i), A.at(i), B.at(i)});
    graph.at(V.at(i)).second.push_back({U.at(i), A.at(i), B.at(i)});
  }
  vector<ll> C(N), D(N);
  rep(i, N){
    cin >> C.at(i) >> D.at(i);
  }
  dp.at(0).at(min(2450LL, S)) = 0;
  priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> q;
  q.push(make_tuple(0, 0, min(2450LL, S)));
  while(!q.empty()){
    tuple<ll, ll, ll> d = q.top();
    //cout << get<0>(d) << " " << get<1>(d) << " " << get<2>(d) << endl;
    q.pop();
    if(dp.at(get<1>(d)).at(get<2>(d)) < get<0>(d)){
      continue;
    }
    for(auto e : graph.at(get<1>(d)).second){
      //cout << "from " << get<1>(d) << " to " << e.to << endl;
      if(e.money > get<2>(d)){
        continue;
      }
      if(chmin(dp.at(e.to).at(get<2>(d)-e.money), get<0>(d)+e.time)){
        q.push(make_tuple(get<0>(d)+e.time, e.to, get<2>(d)-e.money));
        //cout << "push " << get<0>(d)+e.time << " " << e.to << " " << get<2>(d)-e.money << endl;
      }
    }
    if(chmin(dp.at(get<1>(d)).at(min(2450LL, get<2>(d)+C.at(get<1>(d)))), get<0>(d)+D.at(get<1>(d)))){
      q.push(make_tuple(get<0>(d)+D.at(get<1>(d)), get<1>(d), min(2450LL, get<2>(d)+C.at(get<1>(d)))));
      //cout << "push " << get<0>(d)+D.at(get<1>(d)) << " " << get<1>(d) << " " << min(2450LL, get<2>(d)+C.at(get<1>(d))) << endl;
    }
  }
  vector<ll> ans(N-1, INF);
  rep(i, N-1){
    rep(j, 2451){
      chmin(ans.at(i), dp.at(i+1).at(j));
    }
  }
  rep(i, N-1){
    cout << ans.at(i) << endl;
  }
}