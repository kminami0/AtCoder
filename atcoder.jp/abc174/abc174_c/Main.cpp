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
    if(K%2 == 0 || K%5 == 0){
        cout << -1 << endl;
    }
    else{
        ll c = 1;
        ll a = 7;
        while(true){
            if(a % K == 0){
                cout << c << endl;
                return 0;
            }
            else{
                a *= 10;
                a += 7;
                a %= K;
                c++;
            }
        }
    }
}