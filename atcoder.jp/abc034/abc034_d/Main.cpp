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
    vector<long double> w(N), p(N);
    rep(i, N){
        cin >> w.at(i) >> p.at(i);
    }
    long double l = 0;
    long double r = 101;
    rep(i, 100){
        long double c = (l+r) / 2;
        vector<pair<long double, ll>> pri(N);
        rep(j, N){
            pri.at(j) = {w.at(j) * (p.at(j) - c), j};
        }
        sort(all(pri));
        reverse(all(pri));
        long double whole = 0;
        long double salt = 0;
        rep(j, K){
            whole += w.at(pri.at(j).second);
            salt += w.at(pri.at(j).second) * p.at(pri.at(j).second) / 100;
        }
        if(salt / whole * 100 >= c){
            l = c;
        }
        else{
            r = c;
        }
    }
    cout << fixed << setprecision(9);
    cout << l << endl;
}