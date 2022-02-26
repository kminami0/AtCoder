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
int main()
{
    ll N, M;
    cin >> N >> M;
    multiset<ll> pasta;
    rep(i, N){
        ll a;
        cin >> a;
        pasta.insert(a);
    }
    rep(i, M){
        ll b;
        cin >> b;
        if(pasta.find(b) == pasta.end()){
            cout << "No" << '\n';
            return 0;
        }
        pasta.erase(pasta.find(b));
    }
    cout << "Yes" << '\n';
}