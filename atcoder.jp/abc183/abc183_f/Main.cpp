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
vector<map<ll, ll>> cls(200000);
vector<ll> C(200000, 0);

void init(ll n){
  rep(i, n){
    par.at(i) = i;
    cls.at(i)[C.at(i)] = 1;
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
    for(auto p : cls.at(x)){
        cls.at(y)[p.first] += p.second;
    }
  }
  else{
    par.at(y) = x;
    rnk.at(x) += rnk.at(y);
    for(auto p : cls.at(y)){
        cls.at(x)[p.first] += p.second;
    }
  }
}

int main()
{
    ll N, Q;
    cin >> N >> Q;
    rep(i, N){
        cin >> C.at(i);
        C.at(i)--;
    } 
    init(N);
    rep(i, Q){
        ll s;
        cin >> s;
        if(s == 1){
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            unite(a, b);
        }
        else{
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            cout << cls.at(root(x))[y] << endl;
        }
    }
}