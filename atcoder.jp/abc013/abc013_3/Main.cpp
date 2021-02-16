#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 10000000000000 //10^12
#define EPSILON 0.00000000000001 // 10^-14
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
    ll N, H, A, B, C, D, E;
    cin >> N >> H >> A >> B >> C >> D >> E;
    if(H > N*E){
        cout << 0 << '\n';
        return 0;
    }
    ll ans = INF;
    rep(i, N+1){
        if(H + B*i <= (N-i)*E){
            continue;
        }
        if(H + D*i > (N-i)*E){
            chmin(ans, C*i);
            continue;
        }
        ll l = 0;
        ll r = i;
        // 普通の食事をr回、質素な食事をi-r回すれば残りのN-i日をしのげ、普通の食事l回と質素な食事i-l回ではしのげない
        while(r-l>1){
            ll c = (l+r)/2;
            if(H + B*c + D*(i-c) <= (N-i)*E){
                l = c;
            }
            else{
                r = c;
            }
        }
        chmin(ans, A*r + C*(i-r));
    }
    cout << ans << '\n';
}