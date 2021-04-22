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
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    A.push_back(-INF);
    A.push_back(INF);
    sort(all(A));
    ll Q;
    cin >> Q;
    rep(i, Q){
        ll B;
        cin >> B;
        ll l = 0;
        ll r = N+1;
        // A.at(l) < B <= A.at(r);
        while(r-l > 1){
            ll c = (l+r) / 2;
            if(A.at(c) < B){
                l = c;
            }
            else{
                r = c;
            }
        }
        cout << min(B-A.at(l), A.at(r)-B) << '\n';
    }
}