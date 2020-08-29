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
    string S, T;
    cin >> S >> T;
    ll ans = INF;
    rep(i, sz(S)-sz(T)+1){
        ll tmp = 0;
        rep(j, sz(T)){
            if(T.at(j) != S.at(i+j)){
                tmp++;
            }
        }
        chmin(ans, tmp);
    }
    cout << ans << endl;
}