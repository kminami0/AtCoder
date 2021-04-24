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

vector<ll> par(1000000);
vector<ll> rnk(1000000);

void init(ll n){
  rep(i, n){
    par[i] = i;
    rnk[i] = 0;
  }
}

ll root(ll x){
  if(par[x] == x){
    return x;
  }
  else{
    par[x] = root(par[x]);
    return par[x];
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
  if(rnk[x] < rnk[y]){
    par[x] = y;
  }
  else{
    par[y] = x;
    if(rnk[x] == rnk[y]){
      rnk[x]++;
    }
  }
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M);
    rep(i, M){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    ll ans = 0;
    rep(i, 1 << N){
        bitset<20> s(i);
        set<ll> red;
        rep(j, 20){
            if(s.test(j)){
                red.insert(j);
            }
        }
        bool flag = false;
        rep(j, M){
            if(red.count(A[j]) && red.count(B[j])){
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        }
        init(2*N);
        rep(j, M){
            if(red.count(A[j]) || red.count(B[j])){
                continue;
            }
            unite(A[j], B[j]+N);
            unite(A[j]+N, B[j]);
        }
        bool pos = true;
        rep(j, N){
            if(same(j, j+N)){
                pos = false;
                break;
            }
        }
        if(pos){
            set<ll> cc;
            init(2*N);
            rep(j, M){
                if(red.count(A[j]) || red.count(B[j])){
                    continue;
                }
                unite(A[j], B[j]);
            }
            rep(j, N){
                if(red.count(j)){
                    continue;
                }
                cc.insert(root(j));
            }
            ans += pow(2, sz(cc));
        }
    }
    cout << ans << '\n';
}