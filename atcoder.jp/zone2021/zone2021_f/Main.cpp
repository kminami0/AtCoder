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

vector<ll> par(1000000);
vector<ll> rnk(1000000);

void init(ll n){
  rep(i, n){
    par.at(i) = i;
    rnk.at(i) = 1;
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
    rnk.at(y) += rnk.at(x);
  }
  else{
    par.at(y) = x;
    rnk.at(x) += rnk.at(y);
  }
}

int main()
{
    ll N, M;
    cin >> N >> M;
    init(N);
    set<ll> A;
    rep(i, M){
        ll x;
        cin >> x;
        A.insert(x);
    }
    set<ll> base;
    vector<pair<ll, ll>> ans(0);
    rep(i, N){
        if(A.count(i)){
            continue;
        }
        if(same(0, i)){
            continue;
        }
        base.insert(i);
        rep(j, N){
            if(same(j, j ^ i)){
                continue;
            }
            unite(j, j ^ i);
            ans.push_back({j, j ^ i});
        }
    }
    if(rnk.at(0) != N){
        cout << -1 << '\n';
    }
    else{
        for(auto g : ans){
            cout << g.first << ' ' << g.second << '\n';
        }
    }
}