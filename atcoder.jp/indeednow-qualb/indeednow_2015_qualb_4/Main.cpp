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
    ll N, C;
    cin >> N >> C;
    vector<ll> a(N);
    rep(i, N) cin >> a.at(i);
    map<ll, set<ll>> pos;
    rep(i, N){
        pos[a.at(i)].insert(i);
    }
    vector<ll> ans(C, 0);
    rep(i, C){
        ll pre = -1;
        for(auto p : pos.at(i+1)){
            ans.at(i) += (N-p) * (p-pre);
            pre = p;
        }
    }
    rep(i, C){
        cout << ans.at(i) << endl;
    }
}