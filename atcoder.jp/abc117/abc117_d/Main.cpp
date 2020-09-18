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

ll xpow(ll x, ll y){
    if(y == 0){
        return 1;
    }
    return x * xpow(x, y-1);
}

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> bits(41, 0);
    rep(i, N){
        rep(j, 41){
            if(A.at(i) % 2 == 1){
                bits.at(j)++;
            }
            A.at(i) /= 2;
        }
    }
    bitset<41> s(K);
    ll tadoru = 0;
    ll ans = 0;
    rep(i, 41){
        if(s.test(40-i)){
            ll t = xpow(2, 40-i) * (bits.at(40-i));
            rep2(j, i+1, 41){
                if(bits.at(40-j) < (N+1)/2){
                    t += xpow(2, 40-j)*(N-bits.at(40-j));
                }
                else{
                    t += xpow(2, 40-j)*(bits.at(40-j));
                }
            }
            chmax(ans, t+tadoru);
            tadoru += xpow(2, 40-i) * (N-bits.at(40-i));
        }
        else{
            tadoru += xpow(2, 40-i) * (bits.at(40-i));
        }
    }
    chmax(ans, tadoru);
    cout << ans << endl;
}