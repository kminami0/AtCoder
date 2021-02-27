#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll K;
    string S, T;
    cin >> K >> S >> T;
    vector<ll> rem(10, K);
    rem.at(0) = 0;
    vector<ll> taka(10, 0);
    vector<ll> ao(10, 0);
    rep(i, 4){
        rem.at(S.at(i)-'0')--;
        rem.at(T.at(i)-'0')--;
        taka.at(S.at(i)-'0')++;
        ao.at(T.at(i)-'0')++;
    }
    long double ans = 0;
    //高橋君がi、青木君がjの場合を総当たり
    rep2(i, 1, 10){
        if(rem.at(i) == 0){
            continue;
        }
        taka.at(i)++;
        rep2(j, 1, 10){
            if(rem.at(j) == 0){
                continue;
            }
            if(i == j && rem.at(i) == 1){
                continue;
            }
            ao.at(j)++;
            ll tsc = 0;
            ll asc = 0;
            rep2(k, 1, 10){
                tsc += k * pow(10, taka.at(k));
                asc += k * pow(10, ao.at(k));
            }
            if(tsc > asc){
                if(i != j){
                    ans += (long double)(rem.at(i)) / (long double)(9*K - 8) * (long double)(rem.at(j)) / (long double)(9*K - 9);
                }
                else{
                    ans += (long double)(rem.at(i)) / (long double)(9*K - 8) * (long double)(rem.at(i)-1) / (long double)(9*K - 9);
                }
            }
            ao.at(j)--;
        }
        taka.at(i)--;
    }
    cout << fixed << setprecision(18);
    cout << ans << '\n';
}