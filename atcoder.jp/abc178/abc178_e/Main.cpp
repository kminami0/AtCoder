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

ll md(ll x1, ll y1, ll x2, ll y2){
    return abs(x1-x2) + abs(y1-y2);
}

ll id(ll x1, ll y1, ll x2, ll y2){
    max(abs(x2-x1), abs(y2-y1));
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> x(N), y(N);
    rep(i, N){
        cin >> x.at(i) >> y.at(i);
    }
    ll t = -1 * INF;
    rep(i, N){
        chmax(t, x.at(i)-y.at(i));
    }
    ll u = INF;
    rep(i, N){
        chmin(u, x.at(i)-y.at(i));
    }
    ll v = -1 * INF;
    rep(i, N){
        chmax(v, x.at(i)+y.at(i));
    }
    ll w = INF;
    rep(i, N){
        chmin(w, x.at(i)+y.at(i));
    }
    cout << max(t-u, v-w) << endl;
}