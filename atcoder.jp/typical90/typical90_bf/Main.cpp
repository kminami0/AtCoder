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

ll digsum(ll n) {
    ll res = 0;
    while(n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}

int main()
{
    ll N, K;
    cin >> N >> K;
    ll p = 0;
    set<ll> num;
    ll M = N;
    while(!num.count(M)){
        num.insert(M);
        ll y = digsum(M);
        M += y;
        M %= 100000;
    }
    bool loop = false;
    ll cnt = 0;
    ll L = N;
    while(true){
        if(N == M){
            if(loop){
                break;
            }
            loop = true;
        }
        if(loop){
            p++;
        }
        else{
            cnt++;
        }
        ll y = digsum(N);
        N += y;
        N %= 100000;
    }
    if(K < cnt){
        rep(i, K){
            L += digsum(L);
            L %= 100000;
        }
        cout << L << '\n';
    }
    else{
        rep(i, cnt){
            L += digsum(L);
            L %= 100000;
        }
        rep(i, (K-cnt)%p){
            L += digsum(L);
            L %= 100000;
        }
        cout << L << '\n';
    }
}   