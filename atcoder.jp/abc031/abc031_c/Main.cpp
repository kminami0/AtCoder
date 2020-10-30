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
    vector<ll> a(N);
    rep(i, N) cin >> a.at(i);
    vector<ll> aoki(N, -INF);
    vector<ll> takahashi(N, -INF);
    rep(i, N){
        rep(j, N){
            ll aoki_score = 0;
            ll takahashi_score = 0;
            if(i == j){
                continue;
            }
            rep2(k, min(i, j), max(j, i)+1){
                if((k-min(i,j))%2 == 0){
                    takahashi_score += a.at(k);
                }
                else{
                    aoki_score += a.at(k);
                }
            }
            if(chmax(aoki.at(i), aoki_score)){
                takahashi.at(i) = takahashi_score;
            }
        }
    }
    ll ans = -INF;
    rep(i, N){
        chmax(ans, takahashi.at(i));
    }
    cout << ans << endl;
}