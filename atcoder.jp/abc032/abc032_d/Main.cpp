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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll N, W;
    cin >> N >> W;
    vector<ll> v(N), w(N);
    ll maxvalue = 0;
    ll maxweight = 0;
    ll vsum = 0;
    ll wsum = 0;
    rep(i, N){
        cin >> v.at(i) >> w.at(i);
        chmax(maxvalue, v.at(i));
        chmax(maxweight, w.at(i));
        vsum += v.at(i);
        wsum += w.at(i);
    }
    if(maxweight <= 1000){
        if(wsum <= W){
            cout << vsum << '\n';
            return 0;
        }
        vector<vector<ll>> dp(N+1, vector<ll>(W+1, 0));
        rep(i, N){
            rep(j, W+1){
                if(j >= w.at(i)){
                    dp.at(i+1).at(j) = max(dp.at(i).at(j-w.at(i))+v.at(i), dp.at(i).at(j));
                }
                else{
                    dp.at(i+1).at(j) = dp.at(i).at(j);
                }
            }
        }
        cout << dp.at(N).at(W) << '\n';
        return 0;
    }
    if(maxvalue <= 1000){
        vector<vector<ll>> dp(N+1, vector<ll>(vsum+1, INF));
        dp.at(0).at(0) = 0;
        rep(i, N){
            rep(j, vsum+1){
                if(j >= v.at(i)){
                    dp.at(i+1).at(j) = min(dp.at(i).at(j-v.at(i))+w.at(i), dp.at(i).at(j));
                }
                else{
                    dp.at(i+1).at(j) = dp.at(i).at(j);
                }
            }
        }
        rep(i, vsum+1){
            if(dp.at(N).at(vsum-i) <= W){
                cout << vsum-i << '\n';
                return 0;
            }
        }
    }
    ll ans = 0;
    vector<pair<ll, ll>> nap;
    rep(i, 1 << N/2){
        bitset<15> s(i);
        ll wgt = 0;
        ll val = 0;
        rep(j, N/2){
            if(s.test(j)){
                val += v.at(j);
                wgt += w.at(j);
            }
        }
        nap.push_back({wgt, val});
    }
    nap.push_back({-INF, -INF});
    nap.push_back({INF, INF});
    sort(all(nap));
    for(auto it = begin(nap)+1; it != end(nap);){
        if((it-1)->first < it->first && (it-1)->second >= it->second){
            it = nap.erase(it);
        }
        else{
            it++;
        }
    }
    rep(i, 1 << N/2){
        bitset<15> s(i);
        ll wgt = 0;
        ll val = 0;
        rep2(j, N/2, N){
            if(s.test(j-N/2)){
                val += v.at(j);
                wgt += w.at(j);
            }
        }
        ll rem = W - wgt;
        ll l = 0;
        ll r = sz(nap)-1;
        // nap.at(l).first <= rem < nap.at(r).first
        while(r-l > 1){
            ll c = (l+r) / 2;
            if(nap.at(c).first <= rem){
                l = c;
            }
            else{
                r = c;
            }
        }
        chmax(ans, val + nap.at(l).second);
    }
    cout << ans << '\n';
}