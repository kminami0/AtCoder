#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
#define EPSILON 0.00000000000001 // 10^-14
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
    string S;
    cin >> S;
    reverse(all(S));
    vector<ll> cnt(26, 0);
    ll ans = 0;
    rep(i, sz(S)-1){
        if(S.at(i) == S.at(i+1)){
            ans += i - cnt.at(S.at(i)-'a');
            cnt.at(S.at(i)-'a') = i+1;
            rep(j, 26){
                if(j == S.at(i)-'a'){
                    continue;
                }
                cnt.at(j) = 0;
            }
        }
        else{
            cnt.at(S.at(i)-'a')++;
        }
    }
    cout << ans << '\n';
}