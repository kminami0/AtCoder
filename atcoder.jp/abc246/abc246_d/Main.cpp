#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
#define INF 1e18+999999
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

vector<ll> cube(1000001);

int main()
{
    ll N;
    cin >> N;
    if(N == 0){
        cout << 0 << '\n';
        return 0;
    }
    rep(i, 1000001){
        cube.at(i) = lpow(i, 3);
    }
    ll l = 0;
    ll r = 1000000;
    // l^3 < N <= r^3
    while(r-l > 1){
        ll c = (l+r) / 2;
        if(lpow(c, 3) < N){
            l = c;
        }
        else{
            r = c;
        }
    }
    vector<ll> cand(0);
    cand.push_back(lpow(r, 3));
    rep(i, l+1){
        ll a = l - i;
        ll l2 = 0;
        ll r2 = 1000000;
        // (b=l2のときの値) < N <= (b=r2のときの値)
        while(r2-l2 > 1){
            ll c = (l2+r2) / 2;
            if(a*a*a + a*a*c + a*c*c + c*c*c < N){
                l2 = c;
            }
            else{
                r2 = c;
            }
        }
        cand.push_back(a*a*a + a*a*r2 + a*r2*r2 + r2*r2*r2);
    }
    sort(all(cand));
    cout << cand.at(0) << '\n';
}