#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    ll N, Q;
    cin >> N >> Q;
    fenwick_tree<ll> fw(N);
    rep(i, N){
        ll a;
        cin >> a;
        fw.add(i, a);
    }
    rep(i, Q){
        ll t;
        cin >> t;
        if(t == 0){
            ll p, x;
            cin >> p >> x;
            fw.add(p, x);
        }
        else{
            ll l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }
}