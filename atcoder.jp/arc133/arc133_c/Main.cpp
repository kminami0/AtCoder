#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
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
int main()
{
    ll H, W, K;
    cin >> H >> W >> K;
    vector<ll> A(H);
    rep(i, H) cin >> A.at(i);
    vector<ll> B(W);
    rep(i, W) cin >> B.at(i);
    ll sumA = 0;
    ll sumB = 0;
    rep(i, H){
        sumA += A.at(i);
    }
    rep(i, W){
        sumB += B.at(i);
    }
    if((sumA - sumB) % K != 0){
        cout << -1 << '\n';
        return 0;
    }
    ll maxA = 0;
    ll maxB = 0;
    rep(i, H){
        ll diff = ((K - 1) * W) % K - A.at(i);
        if(diff >= 0){
            maxA += (K - 1) * W - diff;
        }
        else{
            maxA += (K - 1) * W - K - diff;
        }
    }
    rep(i, W){
        ll diff = ((K - 1) * H) % K - B.at(i);
        if(diff >= 0){
            maxB += (K - 1) * H - diff;
        }
        else{
            maxB += (K - 1) * H - K - diff;
        }
    }
    cout << min(maxA, maxB) << '\n';
}