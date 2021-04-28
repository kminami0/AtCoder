#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
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
    ll N;
    cin >> N;
    graph.resize(N);
    rep(i, N-1){
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        graph.at(A).push_back({B});
        graph.at(B).push_back({A});
    }
    vector<ll> cost(N, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, 0});
    while(!q.empty()){
        pair<ll, ll> p = q.top();
        q.pop();
        if(cost.at(p.second) < p.first){
            continue;
        }
        else{
            cost.at(p.second) = p.first;
        }
        for(auto e : graph.at(p.second)){
            ll d = cost.at(p.second) + 1;
            if(chmin(cost.at(e.to), d)){
                q.push({cost.at(e.to), e.to});
            }
        }
    }
    set<ll> even, odd;
    rep(i, N){
        if(cost.at(i) % 2 == 0){
            even.insert(i);
        }
        else{
            odd.insert(i);
        }
    }
    ll cnt = 0;
    if(ll(sz(even)) >= N/2){
        for(auto node : even){
            cout << node+1;
            cnt++;
            if(cnt == N/2){
                cout << "\n";
                return 0;
            }
            cout << " ";
        }
    }
    else{
        for(auto node : odd){
            cout << node+1;
            cnt++;
            if(cnt == N/2){
                cout << "\n";
                return 0;
            }
            cout << " ";
        }
    }
}