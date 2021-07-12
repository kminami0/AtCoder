#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
#define EPSILON 1e-14
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
    ll M;
    cin >> M;
    vector<string> sa(M), sb(M);
    rep(i, M){
        string s;
        cin >> s;
        sa.at(i) = s.substr(0, 3);
        sb.at(i) = s.substr(sz(s)-3);
    }
    map<string, ll> mp;
    rep(i, M){
        mp[sa.at(i)] = 0;
        mp[sb.at(i)] = 0;
    }
    ll N = 0;
    for(auto& p : mp){
        p.second = N++;
    }
    graph.resize(N);
    vector<ll> deg(N, 0);
    rep(i, M){
        ll a = mp.at(sa.at(i));
        ll b = mp.at(sb.at(i));
        graph.at(b).push_back({a});
        deg.at(a)++;
    }
    queue<ll> q;
    vector<ll> ans(N, 0);
    rep(i, N){
        if(deg.at(i) == 0){
            ans.at(i) = -1;
            q.push(i);
        }
    }
    while(!q.empty()){
        ll v = q.front();
        q.pop();
        if(ans.at(v) == -1){
            for(edge e : graph.at(v)){
                if(ans.at(e.to) != 0){
                    continue;
                }
                ans.at(e.to) = 1;
                q.push(e.to);
            }
        }
        else{
            for(edge e : graph.at(v)){
                if(ans.at(e.to) != 0){
                    continue;
                }
                deg.at(e.to)--;
                if(deg.at(e.to) == 0){
                    ans.at(e.to) = -1;
                    q.push(e.to);
                }
            }
        }
    }
    rep(i, M){
        if(ans.at(mp.at(sb.at(i))) == 1){
            cout << "Aoki" << '\n';
        }
        else if(ans.at(mp.at(sb.at(i))) == -1){
            cout << "Takahashi" << '\n';
        }
        else{
            cout << "Draw" << '\n';
        }
    }
}