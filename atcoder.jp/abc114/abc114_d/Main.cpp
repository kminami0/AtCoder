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
    Sieve sieve(109);
    vector<vector<pair<int, int>>> pf(101);
    pf.at(0) = {};
    rep(i, N){
        pf.at(i+1) = sieve.factor(i+1);
    }
    vector<vector<pair<int, int>>> ff(101);
    ff.at(0) = {};
    ff.at(1) = {};
    ff.at(2) = {make_pair(2,1)};
    rep(i, N-2){
        ff.at(i+3) = ff.at(i+2);
        ll p = 0;
        ll q = 0;
        while(q != sz(pf.at(i+3))){
            if(p == sz(ff.at(i+2))){
                ff.at(i+3).push_back(pf.at(i+3).at(q));
                q++;
            }
            else{
                if(ff.at(i+3).at(p).first < pf.at(i+3).at(q).first){
                    p++;
                }
                else{
                    ff.at(i+3).at(p).second += pf.at(i+3).at(q).second;
                    p++;
                    q++;
                }
            }
        }
    }
    ll ans = 0;
    //75
    rep(j, sz(ff.at(N))){
        if(ff.at(N).at(j).second >= 74){
            ans++;
        }
    }
    //3*25
    rep(j, sz(ff.at(N))){
        rep2(k, j+1, sz(ff.at(N))){
            if(ff.at(N).at(j).second >= 2 && ff.at(N).at(k).second >= 24){
                ans++;
            }
            if(ff.at(N).at(j).second >= 24 && ff.at(N).at(k).second >= 2){
                ans++;
            }
        }
    }
    // 5*15
    rep(j, sz(ff.at(N))){
        rep2(k, j+1, sz(ff.at(N))){
            if(ff.at(N).at(j).second >= 4 && ff.at(N).at(k).second >= 14){
                ans++;
            }
            if(ff.at(N).at(j).second >= 14 && ff.at(N).at(k).second >= 4){
                ans++;
            }
        }
    }
    // 3*5*5
    rep(j, sz(ff.at(N))){
        rep2(k, j+1, sz(ff.at(N))){
            rep2(l, k+1, sz(ff.at(N))){
                if(ff.at(N).at(j).second >= 2 && ff.at(N).at(k).second >= 4 && ff.at(N).at(l).second >= 4){
                    ans++;
                }
                if(ff.at(N).at(j).second >= 4 && ff.at(N).at(k).second >= 2 && ff.at(N).at(l).second >= 4){
                    ans++;
                }
                if(ff.at(N).at(j).second >= 4 && ff.at(N).at(k).second >= 4 && ff.at(N).at(l).second >= 2){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;   
}