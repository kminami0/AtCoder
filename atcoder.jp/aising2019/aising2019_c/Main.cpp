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
vector<pair<ll, ll>> rnk(1000000);

void init(ll n){
  rep(i, n){
    par.at(i) = i;
    rnk.at(i) = {0, 0};
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
    rnk.at(y).first += rnk.at(x).first;
    rnk.at(y).second += rnk.at(x).second;
  }
  else{
    par.at(y) = x;
    rnk.at(x).first += rnk.at(y).first;
    rnk.at(x).second += rnk.at(y).second;
  }
}

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> S(H+1);
    rep(i, H){
        cin >> S.at(i);
        S.at(i) += "x";
    }
    S.at(H) = "";
    rep(i, W+1){
        S.at(H) += "x";
    }
    init(H*W);
    rep(i, H){
        rep(j, W){
            if(S.at(i).at(j) == '#'){
                rnk.at(i*W+j) = {1, 0};
            }
            else{
                rnk.at(i*W+j) = {0, 1};
            }
        }
    }
    rep(i, H){
        rep(j, W){
            if(S.at(i).at(j) == '#' && S.at(i).at(j+1) == '.'){
                unite(i*W+j, i*W+j+1);
            }
            if(S.at(i).at(j) == '#' && S.at(i+1).at(j) == '.'){
                unite(i*W+j, (i+1)*W+j);
            }
            if(S.at(i).at(j) == '.' && S.at(i).at(j+1) == '#'){
                unite(i*W+j, i*W+j+1);
            }
            if(S.at(i).at(j) == '.' && S.at(i+1).at(j) == '#'){
                unite(i*W+j, (i+1)*W+j);
            }
        }
    }
    set<ll> black;
    rep(i, H){
        rep(j, W){
            if(S.at(i).at(j) == '#'){
                black.insert(root(i*W+j));
            }
        }
    }
//    rep(i, H){
//        rep(j, W){
//            cout << i*W+j << " " << root(i*W+j) << endl;
//        }
//    }
//    for(auto b: black){
//        cout << b << " " << rnk.at(b).first << " " << rnk.at(b).second << endl;
//    }
    ll ans = 0;
    for(auto b : black){
        ans += rnk.at(b).first * rnk.at(b).second;
    }
    cout << ans << endl;
}