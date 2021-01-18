#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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
  ll year;
};
vector<vector<edge>> graph;

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N, M;
    cin >> N >> M;
    graph.resize(N);
    init(N);
    vector<tuple<ll, ll, ll>> roads(M);
    rep(i, M){
        ll a, b, y;
        cin >> a >> b >> y;
        a--;
        b--;
        roads.at(i) = {y, a, b};
    }
    ll Q;
    cin >> Q;
    vector<tuple<ll, ll, ll>> people(Q);
    rep(i, Q){
        ll v, w;
        cin >> v >> w;
        v--;
        people.at(i) = {w, v, i};
    }
    sort(all(roads));
    reverse(all(roads));
    sort(all(people));
    reverse(all(people));
    vector<ll> ans(Q);
    ll j = 0;
    ll k = 0;
    rep(i, M+Q){
        if(j < Q && k < M){
            if(get<0>(people.at(j)) >= get<0>(roads.at(k))){
                ans.at(get<2>(people.at(j))) = rnk.at(root(get<1>(people.at(j))));
                j++;
            }
            else{
                unite(get<1>(roads.at(k)), get<2>(roads.at(k)));
                k++;
            }
        }
        else if(j == Q){
            unite(get<1>(roads.at(k)), get<2>(roads.at(k)));
            k++;
        }
        else{
            ans.at(get<2>(people.at(j))) = rnk.at(root(get<1>(people.at(j))));
            j++;
        }
    }
    rep(i, Q){
        cout << ans.at(i) << '\n';
    }
}