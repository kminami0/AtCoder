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

vector<ll> par(10000000);
vector<ll> rnk(10000000);

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
    ll H, W, Q;
    cin >> H >> W >> Q;
    init(H*W);
    vector<bool> red(H*W, false);
    vector<ll> dx = {-1, 1, 0, 0};
    vector<ll> dy = {0, 0, -1, 1};
    rep(i, Q){
        ll q;
        cin >> q;
        if(q == 1){
            ll r, c;
            cin >> r >> c;
            r--;
            c--;
            red.at(W*r+c) = true;
            rep(j, 4){
                if(0 <= r+dx.at(j) && r+dx.at(j) < H && 0 <= c+dy.at(j) && c+dy.at(j) < W){
                    if(red.at(W*(r+dx.at(j))+c+dy.at(j))){
                        unite(W*r+c, W*(r+dx.at(j))+c+dy.at(j));
                    }
                }
            }
        }
        else{
            ll ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--;
            ca--;
            rb--;
            cb--;
            if(red.at(W*ra+ca) && red.at(W*rb+cb) && same(W*ra+ca, W*rb+cb)){
                cout << "Yes" << '\n';
            }
            else{
                cout << "No" << '\n';
            }
        }
    }
}