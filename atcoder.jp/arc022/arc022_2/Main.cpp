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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    ll ans = 0;
    ll k = 1;
    set<ll> taste;
    bool comp = false;
    rep(i, N){
        rep2(j, k, N+1){
            if(taste.count(A.at(j-1))){
                chmax(ans, ll(sz(taste)));
                k = j;
                taste.erase(A.at(i));
                break;
            }
            else{
                taste.insert(A.at(j-1));
            }
            if(j == N){
                chmax(ans, ll(sz(taste)));
                comp = true;
            }
        }
        if(comp){
            break;
        }
    }
    cout << ans << endl;
}