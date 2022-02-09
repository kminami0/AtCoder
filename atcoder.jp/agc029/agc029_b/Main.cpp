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

ll lpow(ll x, ll y){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    ll a = lpow(x, y / 2);
    return a * a;
  }
  else{
    ll a = lpow(x, y / 2);
    return a * a * x;
  }
}

int main()
{
    ll N;
    cin >> N;
    multiset<ll> A;
    rep(i, N){
        ll a;
        cin >> a;
        A.insert(a);
    }
    auto it = end(A);
    it--;
    ll ans = 0;
    vector<ll> p2(0);
    rep(i, 35){
        p2.push_back(lpow(2, i));
    }
    while(!A.empty()){
        ll x = *it;
        A.erase(it);
        auto it2 = upper_bound(all(p2), x);
        if(A.find(*it2 - x) != end(A)){
            ans++;
            A.erase(A.find(*it2 - x));
        }
        if(A.empty()){
            break;
        }
        it = end(A);
        it--;
    }
    cout << ans << '\n';
}