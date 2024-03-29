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

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
  using P = pair<int, int>;
  int n;
  vector<int> f, primes; //f.at(x)はxの最小素因数
  Sieve(int n=1):n(n), f(n+1) {
  f[0] = f[1] = -1;
  for (ll i = 2; i <= n; ++i) {
    if (f[i]) continue; //ここでf[i]==0なら素数
    primes.push_back(i);
    f[i] = i;
    for (ll j = i*i; j <= n; j += i) {
  if (!f[j]) f[j] = i;
    }
  }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) { //xの素因数を小さい順に列挙
  vector<int> res;
  while (x != 1) {
    res.push_back(f[x]);
    x /= f[x];
  }
  return res;
  }
  vector<P> factor(int x) {
  vector<int> fl = factorList(x);
  if (fl.size() == 0) return {};
  vector<P> res(1, P(fl[0], 0));
  for (int p : fl) { //ここでランレングス圧縮
    if (res.back().first == p) {
  res.back().second++;
    } else {
  res.emplace_back(p, 1);
    }
  }
  return res;
  }
};
// Sieve sieve(N);でN以下の各自然数の最小素因数を調べ上げる
// sieve.factor(M)でMの素因数分解

int main()
{
    ll N, K;
    cin >> N >> K;
    Sieve sieve(N);
    ll ans = 0;
    rep2(j, 2, N+1){
        if(ll(sz(sieve.factor(j))) >= K){
            ans++;
        }
    }
    cout << ans << '\n';
}