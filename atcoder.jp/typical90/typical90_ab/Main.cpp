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
int main()
{
    ll N;
    cin >> N;
    vector<ll> lx(N), ly(N), rx(N), ry(N);
    rep(i, N){
        cin >> lx.at(i) >> ly.at(i) >> rx.at(i) >> ry.at(i);
    }
    vector<vector<ll>> imos(1002, vector<ll>(1002, 0));
    rep(i, N){
        imos.at(lx.at(i)).at(ly.at(i))++;
        imos.at(rx.at(i)).at(ly.at(i))--;
        imos.at(lx.at(i)).at(ry.at(i))--;
        imos.at(rx.at(i)).at(ry.at(i))++;
    }
    rep(i, 1001){
        rep(j, 1000){
            imos.at(j+1).at(i) += imos.at(j).at(i);
        }
    }
    rep(i, 1001){
        rep(j, 1000){
            imos.at(i).at(j+1) += imos.at(i).at(j);
        }
    }
    vector<ll> A(N+1, 0);
    rep(i, 1000){
        rep(j, 1000){
            A.at(imos.at(i).at(j))++;
        }
    }
    rep(i, N){
        cout << A.at(i+1) << '\n';
    }
}