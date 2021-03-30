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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll N;
    cin >> N;
    vector<ll> A(2*N);
    ll sum = 0;
    rep(i, N) cin >> A.at(i), A.at(i+N) = A.at(i), sum += A.at(i);
    vector<ll> acc(2*N+1, 0);
    rep(i, 2*N){
        acc.at(i+1) = acc.at(i) + A.at(i);
    }
    ll l = 0;
    ll r = sum;
    //もっとも小さいピースの大きさをl以上にでき、r以上にはできない
    while(r-l > 1){
        ll c = (l+r) / 2;
        rep(i, N){
            ll l1 = i;
            ll r1 = i+N;
            // i番目とl1番目の切り込みで切ってできるピースの大きさはc未満で、i番目とr1番目だとc以上になる
            while(r1-l1 > 1){
                ll c1 = (l1+r1) / 2;
                if(acc.at(c1) - acc.at(i) >= c){
                    r1 = c1;
                }
                else{
                    l1 = c1;
                }
            }
            if(acc.at(i+N) - acc.at(r1) < c){
                if(i == N-1){
                    r = c;
                }
                continue;
            }
            ll l2 = r1;
            ll r2 = i+N;
            // r1番目とl2番目の切り込みで切ってできるピースの大きさはc未満で、r1番目とr2番目だとc以上になる
            while(r2-l2 > 1){
                ll c2 = (l2+r2) / 2;
                if(acc.at(c2) - acc.at(r1) >= c){
                    r2 = c2;
                }
                else{
                    l2 = c2;
                }
            }
            if(acc.at(i+N) - acc.at(r2) >= c){
                l = c;
                break;
            }
            if(i == N-1){
                r = c;
            }
        }
    }
    cout << l << '\n';
}