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
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> B(N);
    ll mp = INF;
    rep(i, N){
        chmin(mp, A.at(i));
        B.at(i) = A.at(i) - mp;
    }
    ll cnt = 0;
    ll prof = -1;
    rep(i, N){
        if(B.at(i) > prof){
            cnt = 1;
            prof = B.at(i);
        }
        else if(B.at(i) == prof){
            cnt++;
        }
    }
    cout << cnt << endl;
}