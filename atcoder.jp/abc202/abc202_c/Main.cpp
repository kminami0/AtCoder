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
    vector<ll> B(N);
    rep(i, N) cin >> B.at(i);
    vector<ll> C(N);
    rep(i, N) cin >> C.at(i);
    map<ll, ll> Acnt, Ccnt;
    rep(i, N){
        Acnt[A.at(i)]++;
    }
    rep(i, N){
        Ccnt[C.at(i)]++;
    }
    ll ans = 0;
    rep(i, N){
        if(Acnt.count(B.at(i))){
            ans += Acnt[B.at(i)] * Ccnt[i+1];
        }
    }
    cout << ans << '\n';
}