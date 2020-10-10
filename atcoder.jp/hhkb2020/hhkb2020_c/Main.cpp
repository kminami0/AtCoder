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
    vector<ll> p(N);
    rep(i, N) cin >> p.at(i);
    set<ll> S;
    ll ans = 0;
    rep(i, N){
        S.insert(p.at(i));
        while(true){
            if(S.count(ans)){
                ans++;
            }
            else{
                cout << ans << endl;
                break;
            }
        }
    }
}