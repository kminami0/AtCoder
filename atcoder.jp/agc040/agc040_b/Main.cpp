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
    vector<ll> L(N), R(N);
    rep(i, N){
        cin >> L.at(i) >> R.at(i);
        R.at(i)++;
    }
    ll left = 0;
    ll right = INF;
    ll p, q;
    rep(i, N){
        if(chmax(left, L.at(i))){
            p = i;
        }
        if(chmin(right, R.at(i))){
            q = i;
        }
    }
    ll len = 0;
    rep(i, N){
        if(i != p && i != q){
            chmax(len, R.at(i)-L.at(i));
        }
    }
    ll ans = len + max(min(R.at(p), R.at(q)) - max(L.at(p), L.at(q)) , 0LL);
    vector<ll> a(N), b(N);
    rep(i, N){
        a.at(i) = max(R.at(i) - L.at(p), 0LL);
        b.at(i) = max(R.at(q) - L.at(i), 0LL);
    }
    vector<tuple<ll, ll, ll>> c(N);
    rep(i, N){
        c.at(i) = {a.at(i), -b.at(i), i};
    }
    sort(all(c));
    set<ll> t;
    ll mb = INF;
    rep(i, N){
        t.insert(get<2>(c.at(i)));
        chmin(mb, -get<1>(c.at(i)));
        if(t.count(q) && !t.count(p)){
            chmax(ans, get<0>(c.at(i+1))+mb);
        }
        if(t.count(p)){
            break;
        }
    }
    cout << ans << '\n';
}