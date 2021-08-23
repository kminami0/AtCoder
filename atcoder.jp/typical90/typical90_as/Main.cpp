#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
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
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> point(N);
    rep(i, N){
        cin >> point.at(i).first >> point.at(i).second;
    }
    vector<vector<ll>> dp(1<<N, vector<ll>(K+1, INF));
    rep(i, K+1){
        dp.at(0).at(i) = 0;
    }
    vector<ll> d(1<<N, 0);
    rep2(i, 1, 1<<N){
        bitset<15> s(i);
        ll p;
        ll f;
        rep(j, N){
            if(s.test(j)){
                p = i - (1 << j);
                f = j;
            }
        }
        ll dst = 0;
        rep(j, N){
            if(s.test(j)){
                chmax(dst, lpow(point.at(j).first-point.at(f).first, 2)+lpow(point.at(j).second-point.at(f).second, 2));
            }
        }
        d.at(i) = max(dst, d.at(p));
    }
    rep(i, 1<<N){
        rep(j, K){
            for(ll k = (i-1)&i; k != i; k = (k-1) & i){
                //cout << "i:" << i << " " << "j:" << j << " " << "k:" << k << endl;
                chmin(dp.at(i).at(j+1), max(dp.at(k).at(j), d.at(i-k)));
            }
            //cout << i << " " << j+1 << " " << dp.at(i).at(j+1) << endl;
        }
    }
    cout << dp.at((1<<N)-1).at(K) << '\n';
}