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
int main()
{
    ll N;
    cin >> N;
    vector<vector<ll>> D(N, vector<ll>(N));
    rep(i, N){
        rep(j, N){
            cin >> D.at(i).at(j);
        }
    }
    ll Q;
    cin >> Q;
    vector<ll> P(Q);
    rep(i, Q){
        cin >> P.at(i);
    }
    vector<vector<ll>> acc(N+1, vector<ll>(N+1, 0));
    rep(i, N){
        rep(j, N){
            acc.at(i+1).at(j+1) = acc.at(i+1).at(j) + acc.at(i).at(j+1) - acc.at(i).at(j) + D.at(i).at(j);
        }
    }
    vector<ll> deli(N*N+1, 0);
    rep(i, N){
        rep(j, N){
            rep2(k, i, N+1){
                rep2(l, j, N+1){
                    chmax(deli.at((k-i)*(l-j)), acc.at(k).at(l)-acc.at(k).at(j)-acc.at(i).at(l)+acc.at(i).at(j));
                }
            }
        }
    }
    rep(i, N*N){
        if(deli.at(i+1) < deli.at(i)){
            deli.at(i+1) = deli.at(i);
        }
    }
    rep(i, Q){
        cout << deli.at(P.at(i)) << endl;
    }
}