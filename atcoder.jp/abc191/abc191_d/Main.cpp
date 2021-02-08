#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
#define EPSILON 0.00000000000001
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

/*天井と床を求める*/
void cf(long double x, long double r, ll *low, ll *high){

*low = ceil(x-r);
*high = floor(x+r);
}

//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    long double X, Y, R;
    cin >> X >> Y >> R;
    R += EPSILON;
    ll start, end, bottom, top;
    ll num = 0;
    cf(X,R,&start,&end);
    for(ll i=start;i<=end;i++){
        long double p = sqrtl(pow(R,2)-pow((X-(long double)i),2));
        cf(Y,p,&bottom,&top);
        num += top - bottom + 1;
    }
    cout << num << '\n';
}