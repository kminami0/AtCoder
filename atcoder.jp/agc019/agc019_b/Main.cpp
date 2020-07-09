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
    string A;
    cin >> A;
    ll N = sz(A);
    vector<vector<ll>> s(26, vector<ll>(N+1, 0));
    rep(i, N){
        rep(j, 26){
            if(j == A.at(i)-'a'){
                s.at(j).at(i+1) = s.at(j).at(i)+1;
            }
            else{
                s.at(j).at(i+1) = s.at(j).at(i);
            }
        }
    }
    ll ans = 0;
    rep(i, N){
        rep(j, 26){
            if(j == A.at(i) - 'a'){
                continue;
            }
            ans += s.at(j).at(N) - s.at(j).at(i+1);
        }
    }
    cout << ans+1 << endl;
}