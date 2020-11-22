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
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> time;
    vector<ll> time2;
    rep(i, 1 << N/2){
        bitset<20> s(i);
        ll tmp = 0;
        rep(j, N/2){
            if(s.test(j)){
                tmp += A.at(j);
            }
        }
        time.push_back(tmp);
    }
    rep(i, 1 << (N-N/2)){
        bitset<20> s(i);
        ll tmp = 0;
        rep2(j, N/2, N){
            if(s.test(j-N/2)){
                tmp += A.at(j);
            }
        }
        time2.push_back(tmp);
    }
    sort(all(time));
    time2.push_back(-INF);
    time2.push_back(INF);
    sort(all(time2));
    ll ans = 0;
    for(auto p : time){
        ll l = 0;
        ll r = sz(time2)-1;
        // time2.at(l) <= T-p < time2.at(r);
        while(r-l > 1){
            ll c = (l+r) / 2;
            if(time2.at(c) <= T-p){
                l = c;
            }
            else{
                r = c;
            }
        }
        if(time2.at(l) >= 0){
            chmax(ans, p + time2.at(l));
        }
    }
    cout << ans << endl;
}