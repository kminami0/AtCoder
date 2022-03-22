#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
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

ll ngcd(vector<ll> a){
    ll res;
    res = a.at(0);
    for(ll i = 1; i < sz(a) && res != 1; i++) {
        res = gcd(a.at(i), res);
    }
    return res;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), C(M);
    rep(i, M){
        cin >> A.at(i) >> C.at(i);
    }
    vector<ll> v = A;
    v.push_back(N);
    if(ngcd(v) != 1){
        cout << -1 << '\n';
        return 0;
    }
    vector<pair<ll, ll>> ope(M);
    rep(i, M){
        ope.at(i) = {C.at(i), A.at(i)};
    }
    sort(all(ope));
    ll ans = 0;
    vector<ll> X(0);
    X.push_back(N);
    vector<ll> d(M+1);
    d.at(0) = N;
    rep(i, M){
        X.push_back(ope.at(i).second);
        d.at(i+1) = gcd(d.at(i), X.at(i+1));
    }
    rep(i, M){
        ans += ope.at(i).first * (d.at(i) - d.at(i+1));
    }
    cout << ans << '\n';
}
