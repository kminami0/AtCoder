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
    string S;
    cin >> N >> K >> S;
    vector<vector<ll>> c(N+1, vector<ll>(26, INF));
    rep(i, N){
        rep(j, 26){
            if(S.at(N-1-i) == 'a' + j){
                c.at(N-1-i).at(j) = N-1-i;
            }
            else{
                c.at(N-1-i).at(j) = c.at(N-i).at(j);
            }
        }
    }
    string ans = "";
    ll p = 0;
    rep(i, K){
        rep(j, 26){
            if(N - c.at(p).at(j) >= K - i){
                char ch = 'a' + j;
                ans += ch;
                p = c.at(p).at(j) + 1;
                break;
            }
        }
    }
    cout << ans << '\n';
}