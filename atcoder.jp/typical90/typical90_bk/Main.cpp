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
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> P(H, vector<ll>(W));
    rep(i, H){
        rep(j, W){
            cin >> P.at(i).at(j);
        }
    }
    ll ans = 0;
    rep(i, 1 << H){
        bitset<8> s(i);
        vector<ll> cnt(H*W+1, 0);
        vector<ll> choice(0);
        rep(j, H){
            if(s.test(j)){
                choice.push_back(j);
            }
        }
        rep(j, W){
            set<ll> num;
            for(ll c : choice){
                num.insert(P.at(c).at(j));
            }
            if(sz(num) == 1){
                cnt.at(P.at(choice.at(0)).at(j))++;
            }
        }
        sort(all(cnt));
        ll x = cnt.back();
        chmax(ans, ll(sz(choice))*x);
    }
    cout << ans << '\n';
}