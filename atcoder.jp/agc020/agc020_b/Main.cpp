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
    ll K;
    cin >> K;
    vector<ll> A(K+1);
    A.at(0) = 1;
    rep(i, K) cin >> A.at(i+1);
    vector<pair<ll, ll>> est(K+1);
    est.at(K) = {2, 2};
    rep(i, K){
        ll r = est.at(K-i).second % A.at(K-i);
        if(est.at(K-i).first > est.at(K-i).second - r){
            cout << -1 << endl;
            return 0;
        }
        est.at(K-i).second -= r;
        r = est.at(K-i).first % A.at(K-i);
        if(r != 0){
            est.at(K-i).first += A.at(K-i) - r;
        }
        est.at(K-1-i).first = est.at(K-i).first;
        est.at(K-1-i).second = est.at(K-i).second + A.at(K-i) - 1;
    }
    cout << est.at(0).first << " " << est.at(0).second << endl;
}