#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int64_t facc(int64_t k){
    int64_t sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
      sum %= 1000000007;
    }
    return sum;
}

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

long long faccinv(int64_t k){
  if(k==0){
    return 1LL;
  }
  long long sum = 1;
    for (long long i = 1; i <= k; ++i)
    {
        sum *= modinv(i, 1000000007);
      sum %= 1000000007;
    }
    return sum % 1000000007;
}

int main(){
  int64_t X, Y;
  cin >> X >> Y;
  if((X+Y)%3 != 0){
    cout << 0 << endl;
    return 0;
  }
  int64_t c = (X+Y)/3;
  int64_t cnt = 0;
  int64_t res = 0;
  rep(i, c+1){
    if(X==(i+2*(c-i)) && Y==(2*i + (c-i))){
      res = facc(c)*faccinv(i);
      res %= 1000000007;
      res *= faccinv(c-i);
      res %= 1000000007;
      cnt += res;
//      cout << facc(c) << " " << faccinv(i) << " " << faccinv(c-i) << endl;
//      cout << i << " " << cnt << endl;
    }
  }
  cout << cnt % 1000000007 << endl;
}