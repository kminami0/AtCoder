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
    ll N, K;
    cin >> N >> K;
    set<char> D;
    rep(i, K){
        ll a;
        cin >> a;
        D.insert(a+'0');
    }
    ll ans = N;
    while(true){
        string s = to_string(ans);
        rep(i, sz(s)){
            if(D.count(s.at(i))){
                break;
            }
            if(i == sz(s)-1){
                cout << ans << endl;
                return 0;
            }
        }
        ans++;
    }
}