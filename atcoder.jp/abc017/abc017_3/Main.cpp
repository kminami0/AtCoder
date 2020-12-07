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
    vector<ll> l(N), r(N), s(N);
    rep(i, N){
        cin >> l.at(i) >> r.at(i) >> s.at(i);
        l.at(i)--; //0-basedの半開区間にする
    }
    vector<ll> imos(M+1, 0); //いもす法で各宝石を覆う区間のスコアの和を求める
    rep(i, N){
        imos.at(l.at(i)) += s.at(i);
        imos.at(r.at(i)) -= s.at(i);
    }
    ll m = imos.at(0); //各宝石を覆う区間のスコアの和の最小値
    rep(i, M-1){
        imos.at(i+1) += imos.at(i);
        chmin(m, imos.at(i+1));
    }
    ll ans = 0;
    rep(i, N){
        ans += s.at(i);
    }
    ans -= m;
    cout << ans << endl;
}