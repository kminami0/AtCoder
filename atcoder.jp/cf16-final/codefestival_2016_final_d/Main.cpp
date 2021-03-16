#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
#define EPSILON 1e-14
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
    vector<ll> X(N);
    rep(i, N) cin >> X.at(i);
    vector<vector<ll>> rem(M, vector<ll>(0));
    rep(i, N){
        rem.at(X.at(i)%M).push_back(X.at(i));
    }
    rep(i, M){
        sort(all(rem.at(i)));
    }
    ll ans = 0;
    ans += sz(rem.at(0)) / 2;
    if(M % 2 == 0){
        ans += sz(rem.at(M/2)) / 2;
    }
    rep2(i, 1, (M+1)/2){
        vector<ll> S = rem.at(i);
        vector<ll> T = rem.at(M-i);
        if(sz(S) < sz(T)){
            swap(S, T);
        }
        ll diff = sz(S) - sz(T);
        ll cnt = 0;
        rep(i, sz(S)-1){
            if(cnt >= diff / 2){
                break;
            }
            if(S.at(i) == S.at(i+1)){
                cnt++;
                i++;
            }
        }
        ans += cnt + sz(T);
    }
    cout << ans << '\n';
}