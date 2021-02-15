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
    ll W, H;
    cin >> W >> H;
    vector<pair<ll, bool>> cost(W+H);
    rep(i, W){
        cin >> cost.at(i).first;
        cost.at(i).second = true;
    }
    rep(i, H){
        cin >> cost.at(W+i).first;
        cost.at(W+i).second = false;
    }
    sort(all(cost));
    ll a = W + 1;
    ll b = H + 1;
    ll ans = 0;
    ll used = 0;
    ll i = 0;
    while(used < (W+1)*(H+1)-1){
        if(cost.at(i).second){
            ans += cost.at(i).first * min(b, (W+1)*(H+1)-1 - used);
            a--;
            used += min(b, (W+1)*(H+1)-1 - used);
            i++;
        }
        else{
            ans += cost.at(i).first * min(a, (W+1)*(H+1)-1 - used);
            b--;
            used += min(a, (W+1)*(H+1)-1 - used);
            i++;
        }
    }
    cout << ans << '\n';
}