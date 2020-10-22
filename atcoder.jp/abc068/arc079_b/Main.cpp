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
    ll K;
    cin >> K;
    ll r = K % 50;
    vector<ll> a(50, K/50 + 49);
    // Xが50個並ぶ数列では、50*(X-49)回の操作を行う
    // Kが50の倍数でないときは、余りだけ逆向きの操作を行う
    rep(i, r){
        a.at(i) += 50;
        rep(j, 50){
            if(j == i){
                continue;
            }
            a.at(j)--;
        }
    }
    cout << 50 << endl;
    rep(i, 50){
        cout << a.at(i) << " ";
    }
    cout << endl;
}