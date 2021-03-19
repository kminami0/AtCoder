#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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
    ll N, M;
    cin >> N >> M;
    vector<ll> X(M);
    rep(i, M) cin >> X.at(i);
    if(N == M){
        cout << 0 << '\n';
        return 0;
    }
    X.push_back(N+1);
    ll l = 0;
    ll r = 2*N;
    while(r-l > 1){
        ll c = (l+r) / 2;
        vector<ll> D(M+1, 0);
        rep(i, M){
            ll L = X.at(i) - D.at(i) - 1;
            if(L > c){
                break;
            }
            ll l2 = 0;
            ll r2 = N;
            while(r2-l2 > 1){
                ll c2 = (l2+r2) / 2;
                if(min(L*2+c2, L+c2*2) <= c && X.at(i) + c2 < X.at(i+1)){
                    l2 = c2;
                }
                else{
                    r2 = c2;
                }
            }
            D.at(i+1) = X.at(i) + l2;
        }
        if(D.at(M) == N){
            r = c;
        }
        else{
            l = c;
        }
    }
    cout << r << '\n';
}