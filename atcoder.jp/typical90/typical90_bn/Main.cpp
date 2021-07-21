#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
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
    ll N;
    cin >> N;
    vector<ll> L(N), R(N);
    rep(i, N){
        cin >> L.at(i) >> R.at(i);
    }
    long double ans = 0;
    rep(i, N){
        rep2(j, i+1, N){
            ll cnt = 0;
            rep2(k, L.at(i), R.at(i)+1){
                rep2(l, L.at(j), R.at(j)+1){
                    if(k > l){
                        cnt++;
                    }
                }
            }
            ans += (long double)(cnt) / (long double)((R.at(i)-L.at(i)+1)*(R.at(j)-L.at(j)+1));
        }
    }
    cout << fixed << setprecision(20);
    cout << ans << '\n';
}