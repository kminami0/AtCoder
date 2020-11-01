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
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N);
    rep(i, N) cin >> H.at(i);
    vector<ll> W(M);
    rep(i, M) cin >> W.at(i);
    sort(all(H));
    vector<ll> Hl((N-1)/2); //Hl.at(i) = H.at(2*i+1) - H.at(2*i);
    vector<ll> Hr((N-1)/2); //Hr.at(i) = H.at(2*i+2) - H.at(2*i+1);
    rep(i, (N-1)/2){
        Hl.at(i) = H.at(2*i+1) - H.at(2*i);
        Hr.at(i) = H.at(2*i+2) - H.at(2*i+1);
    }
    vector<ll> accl((N+1)/2, 0);
    vector<ll> accr((N+1)/2, 0);
    rep(i, (N-1)/2){
        accl.at(i+1) = accl.at(i) + Hl.at(i);
        accr.at(i+1) = accr.at(i) + Hr.at(i);
    }
    vector<ll> nuke((N+1)/2);
    rep(i, (N+1)/2){
        nuke.at(i) = accl.at(i) + accr.at((N-1)/2) - accr.at(i);
    }
    H.push_back(-1);
    H.push_back(INF);
    sort(all(H));
    ll ans = INF;
    rep(i, M){
        long double x = W.at(i) + 0.1;
        ll l = 0;
        ll r = N+1;
        // H.at(l) <= x < H.at(r)
        while(r-l > 1){
            ll c = (l+r) / 2;
            if(H.at(c) <= x){
                l = c;
            }
            else{
                r = c;
            }
        }
        if((l-1) % 2 == 0){
            chmin(ans, nuke.at((l-1)/2) + W.at(i) - H.at(l));
        }
        else{
            chmin(ans, nuke.at((r-1)/2) + H.at(r) - W.at(i));
        }
    }
    cout << ans << endl;
}