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
    vector<vector<ll>> T(N, vector<ll>(N));
    rep(i, N){
        rep(j, N){
            cin >> T.at(i).at(j);
        }
    }
    vector<ll> root(0);
    rep2(i, 1, N){
        root.push_back(i);
    }
    ll ans = 0;
    do {
        ll dist = 0;
      rep(i, N){
          if(i == 0){
              dist += T.at(0).at(root.at(i));
          }
          else if(i < N-1){
              dist += T.at(root.at(i-1)).at(root.at(i));
          }
          else{
              dist += T.at(root.at(i-1)).at(0);
          }
      }
      if(dist == K){
          ans++;
      }
    } while (next_permutation(root.begin(), root.end()));
    cout << ans << endl;
}