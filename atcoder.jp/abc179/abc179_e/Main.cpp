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
int main()
{
    ll N, X, M;
    cin >> N >> X >> M;
    ll shoki = X;
    set<ll> deta;
    deta.insert(X);
    vector<ll> itsu;
    itsu.push_back(X);
    ll loopl = -1;
    ll loops = 0;
    ll loopg = 0;
    rep(i, M-1){
        X = X * X;
        X %= M;
        if(deta.count(X)){
            rep(j, i+1){
                if(itsu.at(j) == X){
                    loops = j;
                    break;
                }
            }
            loopg = i;
            loopl = loopg - loops + 1;
            break;
        }
        deta.insert(X);
        itsu.push_back(X);
    }
    ll ans = 0;
    X = shoki;
    if(N-1 <= loopg){
        rep(i, N){
            ans += X;
            X = X * X;
            X %= M;
        }
        cout << ans << endl;
        return 0;
    }
    rep(i, loops){
        ans += X;
        X = X * X;
        X %= M;
    }
    N -= loops;
    ll ikkai = 0;
    rep(i, loopl){
        ikkai += X;
        X = X * X;
        X %= M;
    }
    ans += ikkai * (N / loopl);
    rep(i, N % loopl){
        ans += X;
        X = X * X;
        X %= M;
    }
    cout << ans << endl;
}