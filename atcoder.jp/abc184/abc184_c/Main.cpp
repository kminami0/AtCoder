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
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if(r1 == r2 && c1 == c2){
        cout << 0 << endl;
        return 0;
    }
    ll d = abs(r1-r2) + abs(c1-c2);
    ll ans = (d+2)/3;
    ll p = r1+c1;
    ll q = r2+c2;
    if(p == q){
        cout << 1 << endl;
        return 0;
    }
    if(abs(p-q) % 2 == 0){
        chmin(ans, 2LL);
    }
    else if(abs(p-q) <= 3){
        chmin(ans, 2LL);
    }
    else{
        chmin(ans, 3LL);
    }
    p = r1-c1;
    q = r2-c2;
    if(p == q){
        cout << 1 << endl;
        return 0;
    }
    if(abs(p-q) % 2 == 0){
        chmin(ans, 2LL);
    }
    else if(abs(p-q) <= 3){
        chmin(ans, 2LL);
    }
    else{
        chmin(ans, 3LL);
    }
    cout << ans << endl;
}