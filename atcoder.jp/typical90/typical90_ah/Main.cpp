#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
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
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    rep(i, N) cin >> a.at(i);
    ll kind = 0;
    map<ll, ll> num;
    ll ans = 0;
    ll len = 0;
    rep(i, N){
        if(num[a.at(i)] == 0){
            kind++;
        }
        num[a.at(i)]++;
        len++;
        if(kind <= K){
            chmax(ans, len);
        }
        else{
            ll p = i - len + 1;
            while(kind > K){
                num.at(a.at(p))--;
                len--;
                if(num.at(a.at(p)) == 0){
                    kind--;
                }
                p++;
            }
        }
    }
    cout << ans << '\n';
}