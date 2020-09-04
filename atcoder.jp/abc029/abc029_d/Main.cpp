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
    ll N;
    cin >> N;
    ll ans = 0;
    rep(i, 9){
        ans += (N / ll(pow(10, i+1))) * pow(10, i);
        if(i == 0){
            if(N % 10 >= 1){
                ans++;
            }
        }
        else if(N % ll(pow(10, i+1)) >= pow(10, i)){
            ans += min(pow(10, i) , N % ll(pow(10, i+1)) - pow(10, i) + 1);
        }
    }
    cout << ans << endl;
}