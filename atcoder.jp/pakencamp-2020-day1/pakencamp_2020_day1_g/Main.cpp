#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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
    ll ans = -1;
    vector<ll> l(M), r(M), x(M);
    rep(i, M){
      cin >> l.at(i) >> r.at(i) >> x.at(i);
      l.at(i)--;
      r.at(i)--;
    }
    rep(i, 1 << N){
      bitset<14> s(i);
      ll num = 0;
      rep(j, N){
        if(s.test(j)){
          num++;
        }
      }
      bool cont = false;
      rep(j, M){
        ll sub = 0;
        rep2(k, l.at(j), r.at(j)+1){
          if(s.test(k)){
            sub++;
          }
        }
        if(sub != x.at(j)){
          cont = true;
          break;
        }
      }
      if(!cont){
        chmax(ans, num);
      }
    }
    cout << ans << endl;
}