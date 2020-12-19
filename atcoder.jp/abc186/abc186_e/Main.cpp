#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 9 * 1000000000000000000 //9*10^18
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

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

int main()
{
    ll T;
    cin >> T;
    rep(i, T){
        ll N, S, K;
        cin >> N >> S >> K;
        ll d = gcd(N, K);
        if(S % d != 0){
            cout << -1 << endl;
            continue;
        }
        ll x = 0;
        ll y = 0;
        d = extGCD(N, -K, x, y);
        x *= S / d;
        y *= S / d;
        ll M = (-d * y) / N;
        vector<ll> t = {M-3, M-2, M-1, M, M+1, M+2, M+3};
        ll ans = INF;
        for(auto p : t){
            if(y + N/d * p >= 0){
                chmin(ans, y + N/d * p);
            }
        }
        cout << ans << endl;
    }
}