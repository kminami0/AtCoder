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
    string c;
    cin >> c;
    ll hash = 0;
    rep(i, sz(c)){
        hash += c.at(i)-'a'+1;
    }
    ll q = hash / 26;
    ll r = hash % 26;
    string ans = "";
    rep(i, q){
        ans += 'z';
    }
    if(r >= 1){
        ans += 'a' + r - 1;
    }
    if(c != ans){
        cout << ans << endl;
    }
    else if(ans == "zzzzzzzzzzzzzzzzzzzz" || ans == "a"){
        cout << "NO" << endl;
    }
    else if(ans.at(sz(ans)-1) != 'z' && sz(ans) > 1){
        ans.at(sz(ans)-2) = ans.at(sz(ans)-1);
        ans.at(sz(ans)-1) = 'z';
        cout << ans << endl;
    }
    else if(sz(ans) == 1){
        ans.at(0) -= 1;
        ans += 'a';
        cout << ans << endl;
    }
    else{
        ans.at(sz(ans)-1) = 'y';
        ans += 'a';
        cout << ans << endl;
    }
}