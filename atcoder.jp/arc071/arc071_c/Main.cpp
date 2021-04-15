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
    string S, T;
    ll q;
    cin >> S >> T >> q;
    vector<ll> acc(sz(S)+1, 0);
    rep(i, sz(S)){
        acc.at(i+1) = acc.at(i) + S.at(i) - 'A' + 1;
    }
    vector<ll> acct(sz(T)+1, 0);
    rep(i, sz(T)){
        acct.at(i+1) = acct.at(i) + T.at(i) - 'A' + 1;
    }
    rep(i, q){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if((acc.at(b)-acc.at(a-1))%3 == (acct.at(d)-acct.at(c-1))%3){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
}