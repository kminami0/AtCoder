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
    vector<ll> R(N);
    rep(i, N) cin >> R.at(i);
    bool up = false;
    bool down = false;
    ll cnt = 0;
    rep(i, N-1){
        if(R.at(i) < R.at(i+1)){
            if(down){
                cnt++;
            }
            down = false;
            up = true;
        }
        else if(R.at(i) > R.at(i+1)){
            if(up){
                cnt++;
            }
            up = false;
            down = true;
        }
    }
    if(cnt == 0){
        cout << 0 << endl;
    }
    else{
        cout << cnt+2 << endl;
    }
}