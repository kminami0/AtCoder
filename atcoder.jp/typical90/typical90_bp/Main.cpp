#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
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
    ll N, Q;
    cin >> N >> Q;
    init(N);
    vector<ll> T(Q), X(Q), Y(Q), V(Q);
    vector<ll> pif(N-1, -1);
    vector<bool> amb(Q, false);
    rep(i, Q){
        cin >> T.at(i) >> X.at(i) >> Y.at(i) >> V.at(i);
        X.at(i)--;
        Y.at(i)--;
        if(T.at(i) == 0){
            unite(X.at(i), Y.at(i));
            pif.at(X.at(i)) = V.at(i);
        }
        else{
            if(!same(X.at(i), Y.at(i))){
                amb.at(i) = true;
            }
        }
    }
    vector<ll> A(N, 0);
    rep(i, N-1){
        if(pif.at(i) >= 0){
            A.at(i+1) = pif.at(i) - A.at(i);
        }
    }
    rep(i, Q){
        if(T.at(i) == 0){
            continue;
        }
        if(amb.at(i)){
            cout << "Ambiguous" << '\n';
        }
        else{
            ll diff = V.at(i) - A.at(X.at(i));
            if((Y.at(i)-X.at(i)) % 2 == 0){
                cout << A.at(Y.at(i)) + diff << '\n';
            }
            else{
                cout << A.at(Y.at(i)) - diff << '\n';
            }
        }
    }
}