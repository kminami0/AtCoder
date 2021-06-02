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
    ll N, K, P;
    cin >> N >> K >> P;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<vector<ll>> buyf(N/2+1, vector<ll>(0));
    rep(i, 1 << (N/2)){
        bitset<20> s(i);
        ll price = 0;
        ll cnt = 0;
        rep(j, N/2){
            if(s.test(j)){
                cnt++;
                price += A.at(j);
            }
        }
        buyf.at(cnt).push_back(price);
    }
    vector<vector<ll>> buys(N-N/2+1, vector<ll>(0));
    rep(i, 1 << (N-N/2)){
        bitset<20> s(i);
        ll price = 0;
        ll cnt = 0;
        rep(j, N-N/2){
            if(s.test(j)){
                cnt++;
                price += A.at(N/2+j);
            }
        }
        buys.at(cnt).push_back(price);
    }
    rep(i, N-N/2+1){
        if(!buys.at(i).empty()){
            sort(all(buys.at(i)));
        }
    }
    ll ans = 0;
    rep2(i, max(0LL, K-(N-N/2)), min(N/2+1, K+1)){
        for(ll x : buyf.at(i)){
            if(!buys.at(K-i).empty()){
                auto iter = upper_bound(all(buys.at(K-i)), P-x);
                ans += iter - begin(buys.at(K-i));
            }
        }
    }
    cout << ans << '\n';
}