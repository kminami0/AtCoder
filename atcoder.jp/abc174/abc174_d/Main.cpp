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
    ll N;
    string c;
    cin >> N >> c;
    ll ans = 0;
    vector<ll> wp(0), rp(0);
    rep(i, N){
        if(c.at(i) == 'W'){
            wp.push_back(i);
        }
        else{
            rp.push_back(i);
        }
    }
    reverse(all(rp));
    if(sz(wp) == 0 || sz(rp) == 0){
        cout << 0 << endl;
        return 0;
    }
    ll noww = 0;
    ll nowr = 0;
    while(wp.at(noww) < rp.at(nowr)){
        ans++;
        noww++;
        nowr++;
        if(noww >= sz(wp) || nowr >= sz(rp)){
            break;
        }
    }
    cout << ans << endl;
}