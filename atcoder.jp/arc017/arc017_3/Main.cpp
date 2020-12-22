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
    ll N, X;
    cin >> N >> X;
    vector<ll> w(N);
    rep(i, N) cin >> w.at(i);
    map<ll, ll> bag1;
    map<ll, ll> bag2;
    rep(i, 1 << (N/2)){
        bitset<16> s(i);
        ll tmp = 0;
        rep(j, N/2){
            if(s.test(j)){
                tmp += w.at(j);
            }
        }
        bag1[tmp]++;
    }
    rep(i, 1 << (N - N/2)){
        bitset<16> s(i);
        ll tmp = 0;
        rep(j, N - N/2){
            if(s.test(j)){
                tmp += w.at(N/2 + j);
            }
        }
        bag2[tmp]++;
    }
    ll ans = 0;
    for(auto p : bag1){
        ans += p.second * bag2[X-p.first];
    }
    cout << ans << endl;
}