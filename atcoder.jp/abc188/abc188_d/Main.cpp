#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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
    ll N, C;
    cin >> N >> C;
    vector<ll> a(N), b(N), c(N);
    rep(i, N){
        cin >> a.at(i) >> b.at(i) >> c.at(i);
        a.at(i)--;
    }
    vector<ll> v(0);
    rep(i, N){
        v.push_back(a.at(i));
        v.push_back(b.at(i));
    }
    sort(all(v));
    v.erase(std::unique(v.begin(), v.end()), v.end());
    map<ll, ll> comp;
    rep(i, sz(v)){
        comp[v.at(i)] = i;
    }
    vector<ll> imos(sz(v), 0);
    rep(i, N){
        imos.at(comp.at(a.at(i))) += c.at(i);
        imos.at(comp.at(b.at(i))) -= c.at(i);
    }
    rep(i, sz(v)-1){
        imos.at(i+1) += imos.at(i);
    }
    ll ans = 0;
    rep(i, sz(v)-1){
        ans += min(imos.at(i), C) * (v.at(i+1) - v.at(i));
    }
    cout << ans << endl;
}