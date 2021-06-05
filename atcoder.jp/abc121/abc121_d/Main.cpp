#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
#define EPSILON 1e-14
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

ll lpow(ll x, ll y){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    ll a = lpow(x, y / 2);
    return a * a;
  }
  else{
    ll a = lpow(x, y / 2);
    return a * a * x;
  }
}

int main()
{
    ll A, B;
    cin >> A >> B;
    ll ans = 0;
    ll x, y;
    if(A % 2 == 0){
        x = A+1;
    }
    else{
        x = A;
    }
    if(B % 2 == 0){
        y = B-1;
    }
    else{
        y = B;
    }
    ans += ((y - x) / 2 + 1) % 2;
    rep2(i, 2, 41){
        ll c = lpow(2, i);
        ll r = (B-A+1) % c;
        ll s = A % c;
        ll t = (A+r-1) % c;
        if(s / lpow(2, i-1) == 0){
            if(t / lpow(2, i-1) == 1){
                ans += ((t - lpow(2, i-1) + 1) % 2) * lpow(2, i-1);
            }
        }
        else{
            if(t / lpow(2, i-1) == 0){
                ans += ((lpow(2, i) - s) % 2) * lpow(2, i-1);
            }
            else{
                ans += ((abs(t-s) + 1) % 2) * lpow(2, i-1);
            }
        }
    }
    cout << ans << '\n';
}