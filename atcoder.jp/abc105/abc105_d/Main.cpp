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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> acc(N+1, 0);
    rep(i, N){
        acc.at(i+1) = acc.at(i) + A.at(i);
    }
    map<ll, ll> rem;
    set<ll> plu;
    rep(i, N+1){
        rem[acc.at(i) % M]++;
        if(rem[acc.at(i) % M] >= 2){
            plu.insert(acc.at(i) % M);
        }
    }
    ll ans = 0;
    for(auto i : plu){
        ans += rem[i] * (rem[i] - 1) / 2;
    }
    cout << ans << endl;
}