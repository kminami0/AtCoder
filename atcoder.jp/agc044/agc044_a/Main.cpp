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

map<ll, ll> memo;
ll A;
ll B;
ll C;
ll D;

ll f(ll N){
    if(memo.count(N)){
        return memo.at(N);
    }
    if(N == 0){
        memo[0] = 0;
        return 0;
    }
    if(N == 1){
        memo[1] = D;
        return D;
    }
    if(N == 2){
        ll v = min(min(f(1)+A, f(1)+D+B), 2*D);
        memo[2] = v;
        return v;
    }
    if(N == 3){
        ll v = min(min(min(f(1)+D+A, f(1)+B), f(1)+2*D+C), 3*D);
        memo[3] = v;
        return v;
    }
    if(N == 4){
        ll v = min(min(min(f(2)+A, f(1)+D+B), f(1)+D+C), 4*D);
        memo[4] = v;
        return v;
    }
    long double p = (long double)(N);
    ll a = floor(p/2);
    ll b = ceil(p/2);
    ll v1 = f(a)+D*(N-2*a)+A;
    ll v2 = f(b)+D*(2*b-N)+A;
    a = floor(p/3);
    b = ceil(p/3);
    ll v3 = f(a)+D*(N-3*a)+B;
    ll v4 = f(b)+D*(3*b-N)+B;
    a = floor(p/5);
    b = ceil(p/5);
    ll v5 = f(a)+D*(N-5*a)+C;
    ll v6 = f(b)+D*(5*b-N)+C;
    ll v = min(v1, v2);
    chmin(v, v3);
    chmin(v, v4);
    chmin(v, v5);
    chmin(v, v6);
    long double q = (long double)(D);
    long double max = 9223372036854775807;
    if(log10(p)+log10(q) <= log10(max)){
        chmin(v, N*D);
    }
    memo[N] = v;
    return v;
}

int main()
{
    ll T;
    cin >> T;
    rep(i, T){
        memo.clear();
        ll N;
        cin >> N >> A >> B >> C >> D;
        ll ans = f(N);
        cout << ans << endl;
    }
}