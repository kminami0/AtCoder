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
    vector<ll> A(N+1);
    rep(i, N+1) cin >> A.at(i);
    vector<pair<ll, ll>> bur(N+1);
    bur.at(N) = make_pair(A.at(N), A.at(N));
    rep(i, N){
        bur.at(N-i-1) = make_pair((bur.at(N-i).first+1)/2+A.at(N-i-1), bur.at(N-i).second+A.at(N-i-1));
    }
    if(1 < bur.at(0).first || bur.at(0).second < 1){
        cout << -1 << endl;
        return 0;
    }
    vector<ll> tdm(N+1);
    tdm.at(0) = 1;
    rep(i, N){
        tdm.at(i+1) = (tdm.at(i) - A.at(i)) * 2;
        chmin(tdm.at(i+1), bur.at(i+1).second);
    }
    vector<ll> nodes(N+1);
    ll ans = 0;
    rep(i, N+1){
        nodes.at(i) = min(bur.at(i).second, tdm.at(i));
        ans += nodes.at(i);
    }
    cout << ans << endl;
}