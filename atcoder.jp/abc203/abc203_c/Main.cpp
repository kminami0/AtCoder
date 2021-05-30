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
    vector<pair<ll, ll>> friends(N);
    rep(i, N){
        cin >> friends.at(i).first >> friends.at(i).second;
    }
    sort(all(friends));
    ll p = 0;
    ll now = 0;
    while(K != 0){
        if(p <= ll(sz(friends)-1) && friends.at(p).first - now <= K){
            K -= friends.at(p).first - now;
            now = friends.at(p).first;
            K += friends.at(p).second;
            p++;
        }
        else{
            now += K;
            K = 0;
        }
    }
    cout << now << '\n';
}