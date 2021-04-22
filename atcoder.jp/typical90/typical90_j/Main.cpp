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
    vector<ll> C(N), P(N);
    vector<ll> acc1(N+1, 0), acc2(N+1, 0);
    rep(i, N){
        cin >> C.at(i) >> P.at(i);
        if(C.at(i) == 1){
            acc1.at(i+1) = acc1.at(i) + P.at(i);
            acc2.at(i+1) = acc2.at(i);
        }
        else{
            acc1.at(i+1) = acc1.at(i);
            acc2.at(i+1) = acc2.at(i) + P.at(i);
        }
    }
    ll Q;
    cin >> Q;
    rep(i, Q){
        ll L, R;
        cin >> L >> R;
        cout << acc1.at(R) - acc1.at(L-1) << " " << acc2.at(R) - acc2.at(L-1) << '\n';
    }
}