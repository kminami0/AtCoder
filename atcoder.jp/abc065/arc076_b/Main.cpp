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
    ll N;
    cin >> N;
    init(N);
    vector<tuple<ll, ll, ll>> P(N);
    rep(i, N){
        cin >> get<0>(P.at(i)) >> get<1>(P.at(i));
        get<2>(P.at(i)) = i;
    }
    sort(all(P));
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> edges;
    rep(i, N-1){
        edges.push({get<0>(P.at(i+1))-get<0>(P.at(i)), {get<2>(P.at(i)), get<2>(P.at(i+1))}});
    }
    rep(i, N){
        swap(get<0>(P.at(i)), get<1>(P.at(i)));
    }
    sort(all(P));
    rep(i, N-1){
        edges.push({get<0>(P.at(i+1))-get<0>(P.at(i)), {get<2>(P.at(i)), get<2>(P.at(i+1))}});
    }
    ll cnt = 0;
    ll ans = 0;
    while(cnt < N-1){
        pair<ll, pair<ll, ll>> edge = edges.top();
        edges.pop();
        if(!same(edge.second.first, edge.second.second)){
            ans += edge.first;
            unite(edge.second.first, edge.second.second);
            cnt++;
        }
    }
    cout << ans << endl;
}