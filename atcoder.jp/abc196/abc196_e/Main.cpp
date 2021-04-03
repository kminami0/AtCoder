#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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
    vector<ll> a(N), t(N);
    rep(i, N){
        cin >> a.at(i) >> t.at(i);
    }    
    ll Q;
    cin >> Q;
    vector<ll> x(Q);
    rep(i, Q) cin >> x.at(i);
    ll S = 0;
    rep(i, N){
        if(t.at(i) == 1){
            S += a.at(i);
        }
    }
    ll p = -INF;
    rep(i, N){
        if(t.at(i) == 1){
            p += a.at(i);
        }
        else if(t.at(i) == 2){
            p = max(p, a.at(i));
        }
        else{
            p = min(p, a.at(i));
        }
    }
    ll l = p - S;
    ll lv = p;
    p = INF;
    rep(i, N){
        if(t.at(i) == 1){
            p += a.at(i);
        }
        else if(t.at(i) == 2){
            p = max(p, a.at(i));
        }
        else{
            p = min(p, a.at(i));
        }
    }
    ll r = p - S;
    ll rv = p;
    rep(i, Q){
        if(x.at(i) <= l){
            cout << lv << '\n';
        }
        else if(x.at(i) >= r){
            cout << rv << '\n';
        }
        else{
            cout << x.at(i) + S << '\n';
        }
    }
}