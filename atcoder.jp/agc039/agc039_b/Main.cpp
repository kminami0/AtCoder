#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
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
vector<map<ll, ll>> mv;
vector<queue<ll>> det;

void bfs(ll x, ll d, ll i){
    if(mv.at(i).count(x)){
        return;
    }
    mv.at(i)[x] = d + 1;
    det.at(i).push(x);
}

int main()
{
    ll N;
    cin >> N;
    graph.resize(N);
    mv.resize(N);
    det.resize(N);
    vector<string> S(N);
    rep(i, N){
        cin >> S.at(i);
    }
    rep(i, N){
        rep(j, N){
            if(S.at(i).at(j) == '1'){
                graph.at(i).push_back({j});
            }
        }
    }
    rep(i, N){
        mv.at(i)[i] = 0;
        det.at(i).push(i);
        while(!det.at(i).empty()){
            ll x = det.at(i).front();
            det.at(i).pop();
            ll d = mv.at(i).at(x);
            for(auto e : graph.at(x)){
                 bfs(e.to, d, i);
            }
        }
    }
    vector<ll> ans(N, -2);
    bool flag = false;
    rep(j, N){
        rep(i, N){
            chmax(ans.at(j), mv.at(j).at(i));
            for(auto e : graph.at(i)){
                if(mv.at(j).at(i) == mv.at(j).at(e.to)){
                    ans.at(j) = -2;
                    flag = true;
                    break;
                }
            }
            if(flag){
                flag = false;
                break;
            }
        }
    }
    ll m = -2;
    rep(i, N){
        chmax(m, ans.at(i));
    }
    m++;
    cout << m << endl;
}