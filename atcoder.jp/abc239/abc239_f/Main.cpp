#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
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

vector<ll> par(1000000);
vector<ll> rnk(1000000);

void init(ll n){
  rep(i, n){
    par.at(i) = i;
    rnk.at(i) = 0;
  }
}

ll root(ll x){
  if(par.at(x) == x){
    return x;
  }
  else{
    par.at(x) = root(par.at(x));
    return par.at(x);
  }
}

bool same(ll x, ll y){
  if(root(x) == root(y)){
    return true;
  }
  else{
    return false;
  }
}

void unite(ll x, ll y){
  x = root(x);
  y = root(y);
  if(x == y){
    return;
  }
  if(rnk.at(x) < rnk.at(y)){
    par.at(x) = y;
  }
  else{
    par.at(y) = x;
    if(rnk.at(x) == rnk.at(y)){
      rnk.at(x)++;
    }
  }
}

int main()
{
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    vector<ll> D(N);
    rep(i, N) cin >> D.at(i);
    init(N);
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).push_back({b});
        graph.at(b).push_back({a});
        unite(a, b);
        D.at(a)--;
        D.at(b)--;
    }
    rep(i, N){
        if(D.at(i) < 0){
            cout << -1 << '\n';
            return 0;
        }
    }
    map<ll, ll> cc;
    rep(i, N){
        cc[root(i)] += D.at(i);
    }
    for(pair<ll, ll> p : cc){
        if(p.second == 0){
            cout << -1 << '\n';
            return 0;
        }
    }
    ll ds = 0;
    for(pair<ll, ll> p : cc){
        ds += p.second;
    }
    if(ds != 2 * (sz(cc)-1)){
        cout << -1 << '\n';
        return 0;
    }
    map<ll, vector<ll>> S;
    rep(i, N){
        rep(j, D.at(i)){
            S[root(i)].push_back(i);
        }
    }
    priority_queue<pair<ll, ll>> q;
    rep(i, N){
        if(i == root(i)){
            if(sz(S.at(i)) == 0){
                cout << -1 << '\n';
                return 0;
            }
            q.push({sz(S.at(i)), i});
        }
    }
    vector<pair<ll, ll>> ans(0);
    while(sz(q) > 1){
        pair<ll, ll> p1, p2;
        p1 = q.top();
        q.pop();
        p2 = q.top();
        q.pop();
        auto it1 = end(S.at(p1.second))-1;
        auto it2 = end(S.at(p2.second))-1;
        ans.push_back({*it1, *it2});
        S.at(p1.second).pop_back();
        S.at(p2.second).pop_back();
        ll d = p1.first + p2.first - 2;
        unite(p1.second, p2.second);
        ll x = root(p1.second);
        ll y;
        if(x == p1.second){
            y = p2.second;
        }
        else{
            y = p1.second;
        }
        for(ll z : S.at(y)){
            S.at(x).push_back(z);
        }
        if(d > 0){
            q.push({d, root(p1.second)});
        }
    }
    if(sz(ans) != N-M-1){
        cout << -1 << '\n';
        return 0;
    }
    rep(i, N-M-1){
        cout << ans.at(i).first+1 << ' ' << ans.at(i).second+1 << '\n';
    }
}