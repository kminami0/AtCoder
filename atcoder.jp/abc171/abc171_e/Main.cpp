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
    vector<ll> a(N);
    rep(i, N) cin >> a.at(i);
    vector<ll> c(N/2);
    rep(i, N/2){
        c.at(i) = a.at(2*i)^a.at(2*i+1);
    }
    ll d = 0;
    rep(i, N/2){
        d = d^c.at(i);
    }
    vector<ll> b(N);
    rep(i, N){
        b.at(i) = a.at(i)^d;
    }
    rep(i, N-1){
        cout << b.at(i) << " ";
    }
    cout << b.at(N-1) << endl;
}