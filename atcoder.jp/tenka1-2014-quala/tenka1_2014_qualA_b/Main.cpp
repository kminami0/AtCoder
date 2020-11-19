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
    string S;
    cin >> S;
    ll kaburin = 5;
    ll charge = 0;
    vector<ll> damage(sz(S)+10, 0);
    ll ans = 0;
    ll combo = 0;
    vector<ll> back(sz(S)+10, 0);
    rep(i, sz(S)){
        if(damage.at(i) > 0){
            ans += damage.at(i);
            combo++;
        }
        kaburin += back.at(i);
        if(charge > 0){
            charge--;
        }
        if(S.at(i) == '-'){
            continue;
        }
        if(S.at(i) == 'N' && kaburin >= 1 && charge == 0){
            charge = 1;
            kaburin--;
            damage.at(i+2) = 10 + combo / 10;
            back.at(i+7) = 1;
        }
        if(S.at(i) == 'C' && kaburin >= 3 && charge == 0){
            charge = 3;
            kaburin -= 3;
            damage.at(i+4) = 50 + combo / 10 * 5;
            back.at(i+9) = 3;
        }
    }
    rep2(i, sz(S), sz(S)+10){
        ans += damage.at(i);
    }
    cout << ans << endl;
}