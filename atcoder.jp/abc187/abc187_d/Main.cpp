#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    ll aoki = 0;
    priority_queue<ll> takahashi;
    rep(i, N){
        cin >> A.at(i) >> B.at(i);
        aoki += A.at(i);
        takahashi.push(2*A.at(i)+B.at(i));
    }
    ll chase = 0;
    ll ans = 0;
    while(true){
        ll p = takahashi.top();
        takahashi.pop();
        chase += p;
        ans++;
        if(chase > aoki){
            cout << ans << endl;
            return 0;
        }
    }
}