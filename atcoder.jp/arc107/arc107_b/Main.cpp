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
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    rep2(i, 2, 2*N+1){
        if(K+i > 2*N){
            break;
        }
        if(K+i < 2){
            continue;
        }
        if(N < K+i-1){
            if(N < i-1){
                ans += abs(2*N-i+1) * abs(2*N-K-i+1);
            }
            else{
                ans += (i-1) * abs(2*N-K-i+1);
            }
        }
        else{
            if(N < i-1){
                ans += abs(2*N-i+1) * (K+i-1);
            }
            else{
                ans += (i-1) * (K+i-1);
            }
        }
    }
    cout << ans << endl;
}