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
    vector<ll> x(N), y(N);
    rep(i, N){
        cin >> x.at(i) >> y.at(i);
    }
    // 2直線y=100-r, y=-100+rで囲まれた通路にN本の半径rの釘があり、点が通過できるかどうか、という問題に言い換える
    // 通過可能と通過不可能の境界を二分探索で求める
    long double ac = 0;
    long double wa = 101;
    rep(i, 100){
      init(N+2);
      long double wj = (ac + wa) / 2;
      rep(j, N+2){
        rep2(k, j+1, N+2){
          if(k < N){
            if(pow(x.at(j)-x.at(k), 2) + pow(y.at(j)-y.at(k), 2) <= pow(2 * wj, 2)){
              unite(j, k);
            }
          }
          else if(k == N){
            if(100 - y.at(j) <= 2 * wj){
              unite(j, k);
            }
          }
          else if(j < N){
            if(y.at(j) + 100 <= 2 * wj){
              unite(j, k);
            }
          }
        }
      }
      if(same(N, N+1)){
        wa = wj;
      }
      else{
        ac = wj;
      }
    }
    cout << fixed << setprecision(18);
    cout << ac << endl;
}