#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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

ll N;
vector<vector<ll>> edges(200000);
vector<ll> depth(200000, -1);

void dfs(ll a, ll d){
    depth.at(a) = d;
    for(auto v : edges.at(a)){
        if(depth.at(v) == -1){
          dfs(v, d+1);
        }
    }
}

vector<ll> dp(200000, 0);

void imos(ll a, ll now){
    now += dp.at(a);
    dp.at(a) = now;
    for(auto v : edges.at(a)){
        if(depth.at(v) > depth.at(a)){
            imos(v, now);
        }
    }
}

int main()
{
    cin >> N;
    vector<ll> A(N-1);
    vector<ll> B(N-1);
    rep(i, N-1){
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
        edges.at(A.at(i)).push_back(B.at(i));
        edges.at(B.at(i)).push_back(A.at(i));
    }
    dfs(0, 0);
    ll Q;
    cin >> Q;
    rep(i, Q){
        ll t, e, x;
        cin >> t >> e >> x;
        e--;
        ll va, vb;
        if(t == 1){
            va = A.at(e);
            vb = B.at(e);
        }
        else{
            va = B.at(e);
            vb = A.at(e);
        }
        //通る方が親
        if(depth.at(va) < depth.at(vb)){
            dp.at(0) += x;
            dp.at(vb) -= x;
        }
        else{
            dp.at(va) += x;
        }
    }
    imos(0, 0);
    rep(i, N){
        cout << dp.at(i) << endl;
    }
}