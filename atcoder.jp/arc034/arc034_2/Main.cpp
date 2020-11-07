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

ll digit_sum(ll x){
    ll val = 0;
    while(x > 0){
        val += x % 10;
        x /= 10;
    }
    return val;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> ans(0);
    rep(i, 163){
        if(digit_sum(N-i) == i){
            ans.push_back(N-i);
        }
    }
    reverse(all(ans));
    cout << sz(ans) << endl;
    rep(i, sz(ans)){
        cout << ans.at(i) << endl;
    }
}