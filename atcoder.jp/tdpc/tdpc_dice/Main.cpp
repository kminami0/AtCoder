#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000000
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
  ll n;
  vector<ll> f, primes;
  Sieve(ll n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(ll x) { return f[x] == x;}
  vector<ll> factorList(ll x) {
    vector<ll> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(ll x) {
    vector<ll> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (ll p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};

double dp[101][61][61][61];

int main(){
  	ll N, D;
	cin >> N >> D;
	int tw = 0;
	int th = 0;
	int fv = 0;
  while(D % 2 == 0){
    D /= 2;
    tw++;
  }
  while(D % 3 == 0){
    D /= 3;
    th++;
  }
  while(D % 5 == 0){
    D /= 5;
    fv++;
  }
  if(D > 1){
    cout << 0.0 << endl;
    return 0;
  }
    dp[0][0][0][0] = 1;
	rep(i, N) {
		rep(j, tw + 1) {
			rep(k, th + 1) {
				rep(l, fv + 1) {
					dp[(i + 1)][j][k][l] += 1.0 / 6.0 * dp[i][j][k][l];
					dp[(i + 1)][min(j + 1, tw)][k][l] += 1.0 / 6.0 * dp[i][j][k][l];
					dp[(i + 1)][j][min(k + 1, th)][l] += 1.0 / 6.0 * dp[i][j][k][l];
					dp[(i + 1)][min(j + 2, tw)][k][l] += 1.0 / 6.0 * dp[i][j][k][l];
					dp[(i + 1)][j][k][min(l + 1, fv)] += 1.0 / 6.0 * dp[i][j][k][l];
					dp[(i + 1)][min(j + 1, tw)][min(k + 1, th)][l] += 1.0 / 6.0 * dp[i][j][k][l];
				}
			}
		}
	}
    cout << fixed << setprecision(9);
	cout << dp[N][tw][th][fv] << endl;
}