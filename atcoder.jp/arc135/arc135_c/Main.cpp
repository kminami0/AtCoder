#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
#define INF 1e18+999999
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

ll lpow(ll x, ll y){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    ll a = lpow(x, y / 2);
    return a * a;
  }
  else{
    ll a = lpow(x, y / 2);
    return a * a * x;
  }
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    ll sum = 0;
    vector<ll> flag(30, 0);
    rep(i, N){
        sum += A.at(i);
        bitset<30> s(A.at(i));
        rep(j, 30){
            if(s.test(j)){
                flag.at(j)++;
            }
        }
    }
    ll ans = sum;
    rep(i, N){
        ll tmp = sum;
        bitset<30> s(A.at(i));
        rep(j, 30){
            if(s.test(j)){
                tmp -= lpow(2, j) * flag.at(j);
                tmp += lpow(2, j) * (N - flag.at(j));
            }
        }
        chmax(ans, tmp);
    }
    cout << ans << '\n';
}