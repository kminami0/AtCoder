#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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

vector<ll> par(1000000);
vector<ll> rnk(1000000);
vector<vector<ll>> cost(1000000, vector<ll>(0));

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
    rep(i, sz(cost.at(x))){
        cost.at(y).push_back(cost.at(x).at(i));
    }
  }
  else{
    par.at(y) = x;
    if(rnk.at(x) == rnk.at(y)){
      rnk.at(x)++;
    }
    rep(i, sz(cost.at(y))){
        cost.at(x).push_back(cost.at(y).at(i));
    }
  }
}

int main()
{
    ll N, M;
    cin >> N >> M;
    if(M == N-1){
        cout << 0 << '\n';
        return 0;
    }
    if(N < 2*(N-M-1)){
        cout << "Impossible" << '\n';
        return 0;
    }
    init(N);
    rep(i, N){
        ll a;
        cin >> a;
        cost.at(i).push_back(a);
    }
    rep(i, M){
        ll x, y;
        cin >> x >> y;
        unite(x, y);
    }
    set<ll> con;
    rep(i, N){
        con.insert(root(i));
    }
    ll ans = 0;
    for(auto p : con){
        sort(all(cost.at(p)));
        ans += cost.at(p).at(0);
        cost.at(p).erase(begin(cost.at(p)));
    }
    vector<ll> rem(0);
    for(auto p : con){
        rep(i, sz(cost.at(p))){
            rem.push_back(cost.at(p).at(i));
        }
    }
    sort(all(rem));
    rep(i, 2*(N-M-1)-sz(con)){
        ans += rem.at(i);
    }
    cout << ans << '\n';
}