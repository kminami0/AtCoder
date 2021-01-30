#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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
    vector<ll> A(M), B(M);
    rep(i, M){
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
    }
    ll K;
    cin >> K;
    vector<ll> C(K), D(K);
    rep(i, K){
        cin >> C.at(i) >> D.at(i);
        C.at(i)--;
        D.at(i)--;
    }
    ll ans = 0;
    rep(i, 1 << K){
        bitset<16> s(i);
        vector<bool> sara(N, false);
        rep(j, K){
            if(s.test(j)){
                sara.at(D.at(j)) = true;
            }
            else{
                sara.at(C.at(j)) = true;
            }
        }
        ll tmp = 0;
        rep(j, M){
            if(sara.at(A.at(j)) && sara.at(B.at(j))){
                tmp++;
            }
        }
        chmax(ans, tmp);
    }
    cout << ans << '\n';
}