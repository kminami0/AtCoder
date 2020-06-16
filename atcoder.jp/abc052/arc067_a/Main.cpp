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

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
  if ((x += a.x) >= mod) x -= mod;
  return *this;
  }
  mint& operator-=(const mint a) {
  if ((x += mod-a.x) >= mod) x -= mod;
  return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
  if (!t) return 1;
  mint a = pow(t>>1);
  a *= a;
  if (t&1) a *= *this;
  return a;
  }
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

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
    ll N;
    cin >> N;
    Sieve sieve(N);
    vector<ll> pf(0);
    for(auto p : sieve.primes){
        ll i = 1;
        ll cnt = 0;
        ll q = p;
        while(q <= N){
            cnt += N / q;
            q *= p;
        }
        pf.push_back(cnt);
    }
    mint ans = 1;
    for(auto c : pf){
        ans *= c + 1;
    }
    cout << ans << endl;
}