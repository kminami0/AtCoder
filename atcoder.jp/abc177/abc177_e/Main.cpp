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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

ll ngcd(vector<ll> a){
    ll res;
    res = a.at(0);
    for(ll i = 1; i < a.size() && res != 1; i++) {
        res = gcd(a.at(i), res);
    }
    return res;
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

vector<pair<long long, long long> > prime_factorize(long long N) {
  vector<pair<long long, long long> > res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0; // 指数
    // 割れる限り割り続ける
    while (N % a == 0) {
     ++ex;
      N /= a;
    }
    // その結果を push
    res.push_back({a, ex});
  }
  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    Sieve sieve(1000009);
    set<int> primes;
    bool pc = true;
    rep(i, N){
        vector<pair<int, int>> pf = sieve.factor(A.at(i));
        rep(j, sz(pf)){
            if(primes.count(pf.at(j).first)){
                pc = false;
                break;
            }
            else{
                primes.insert(pf.at(j).first);
            }
        }
        if(!pc){
            break;
        }
    }
    if(pc){
        cout << "pairwise coprime" << endl;
        return 0;
    }
    if(ngcd(A) == 1){
        cout << "setwise coprime" << endl;
    }
    else{
        cout << "not coprime" << endl;
    }
}