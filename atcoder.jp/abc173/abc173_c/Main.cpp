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
  ll H, W, K;
  cin >> H >> W >> K;
  vector<string> c(H);
  rep(i, H){
    cin >> c.at(i);
  }
  ll ans = 0;
  rep(i, 1 << H){
    rep(j, 1 << W){
      bitset<6> s(i);
      bitset<6> t(j);
      vector<string> d(H);
      rep(k, H){
        d.at(k) = c.at(k);
      }
      rep(k, H){
        if(s.test(k)){
          rep(l, W){
            d.at(k).at(l) = '.';
          }
        }
      }
      rep(k, W){
        if(t.test(k)){
          rep(l, H){
            d.at(l).at(k) = '.';
          }
        }
      }
      ll cnt = 0;
      rep(k, H){
        rep(l, W){
          if(d.at(k).at(l) == '#'){
            cnt++;
          }
        }
      }
      if(cnt == K){
        ans++;
      }
    }
  }
  cout << ans << endl;
}