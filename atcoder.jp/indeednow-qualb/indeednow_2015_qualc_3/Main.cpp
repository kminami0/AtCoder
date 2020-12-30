#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

struct edge {
  ll to;
};
vector<vector<edge>> graph;

int main()
{
    ll N;
    cin >> N;
    graph.resize(N);
    rep(i, N-1){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).push_back({b});
        graph.at(b).push_back({a});
    }
    priority_queue<ll, vector<ll>, greater<ll>> q;
    q.push(0);
    vector<ll> ans(0);
    vector<bool> vst(N, false);
    vst.at(0) = true;
    while(!q.empty()){
        ll p = q.top();
        q.pop();
        ans.push_back(p+1);
        for(auto e : graph.at(p)){
            if(vst.at(e.to)){
                continue;
            }
            vst.at(e.to) = true;
            q.push(e.to);
        }
    }
    rep(i, N-1){
        cout << ans.at(i) << " ";
    }
    cout << ans.at(N-1) << endl;
}