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
    cin >> N;
    ll dist = 0;
    ll ans = 0;
    ll tmp  = 0;
    ll v = 0;
    rep(i, N-1){
        cout << "? " << 1 << " " << i+2 << endl;
        cin >> dist;
        if(chmax(tmp, dist)){
            v = i + 2;
        }
    }
    rep(i, N){
        if(i+1 == v){
            continue;
        }
        cout << "? " << v << " " << i+1 << endl;
        cin >> dist;
        chmax(ans, dist);
    }
    cout << "! " << ans << endl;
}