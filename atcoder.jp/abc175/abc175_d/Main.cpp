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
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N);
    rep(i, N) cin >> P.at(i);
    rep(i, N){
        P.at(i)--;
    }
    vector<ll> C(N);
    rep(i, N) cin >> C.at(i);
    vector<vector<ll>> score(N, vector<ll>(N+1, 0));
    vector<ll> loop(N, 0);
    rep(i, N){
        ll now = i;
        bool ring = false;
        rep(j, N){
            score.at(i).at(j+1) = score.at(i).at(j) + C.at(P.at(now));
            now = P.at(now);
            if(now == i && !ring){
                loop.at(i) = j+1;
                ring = true;
            }
        }
    }
    ll ans = -1 * INF;
    rep(i, N){
        rep2(j, 1, min(K, N)+1){
            chmax(ans, score.at(i).at(j));
        }
    }
    if(K <= N){
        cout << ans << endl;
        return 0;
    }
    rep(i, N){
        ll tmp = 0;
        ll q = K / loop.at(i);
        ll r = K % loop.at(i);
        if(q >= 2){
            tmp += (q-1) * score.at(i).at(loop.at(i));
            chmax(ans, tmp);
            ll now = i;
            rep(j, r+loop.at(i)){
                tmp += C.at(P.at(now));
                chmax(ans, tmp);
                now = P.at(now);
            }
        }
        else{
            tmp += q * score.at(i).at(loop.at(i));
            chmax(ans, tmp);
            ll now = i;
            rep(j, r){
                tmp += C.at(P.at(now));
                chmax(ans, tmp);
                now = P.at(now);
            }
        }
    }
    cout << ans << endl;
}