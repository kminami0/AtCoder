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
    ll N, R;
    string S;
    cin >> N >> R >> S;
    ll ans = 0;
    ll np = -1;
    rep(i, N){
        if(S.at(i) == '.'){
            np = i;
        }
    }
    if(np == -1){
        cout << 0 << '\n';
        return 0;
    }
    rep(i, N){
        if(i+R-1 >= np){
            cout << ans+1 << '\n';
            return 0;
        }
        else if(S.at(i) == '.'){
            rep2(j, i, min(i+R-1, N-1)+1){
                S.at(j) = 'o';
            }
            ans += 2;
        }
        else{
            ans++;
        }
    }
}