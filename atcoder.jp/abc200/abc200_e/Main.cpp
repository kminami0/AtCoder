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

ll com2(ll x){
    if(x < 2){
        return 0;
    }
    return x * (x - 1) / 2;
}

ll N;

ll cake_num(ll x){ //合計がxのケーキは何個あるか
    return com2(x-1) - com2(x-1-N) * 3 + com2(x-1-2*N) * 3 - com2(x-1-3*N);
}

ll cake_num2(ll x, ll y){ //合計がxで綺麗さがyのケーキは何個あるか
    if(y <= 0 || y >= x-1 || y >= N+1 || y + 2*N < x){
        return 0;
    }
    x -= y;
    ll lb = max(x-N, 1LL);
    ll ub = min(N, x-1);
    return ub - lb + 1;
}

int main()
{
    ll K;
    cin >> N >> K;
    ll cnt = 0;
    ll p = 2;
    while(cnt < K){
        p++;
        cnt += cake_num(p);
    }
    cnt -= cake_num(p);
    ll q = 0;
    while(cnt < K){
        q++;
        cnt += cake_num2(p, q);
    }
    cnt -= cake_num2(p, q);
    ll r = max(p-q-N, 1LL) - 1;
    r += K - cnt;
    cout << q << " " << r << " " << p-q-r << '\n';
}