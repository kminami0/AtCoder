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
    ll N, K;
    cin >> N >> K;
    vector<ll> s(N);
    rep(i, N) cin >> s.at(i);
    rep(i, N){
        if(s.at(i) == 0){
            cout << N << endl;
            return 0;
        }
    }
    if(K == 0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    ll tmp = 1;
    ll p = 0;
    ll q = 1;
    rep(i, N){
        q--;
        if(s.at(i) > K){
            if(p == i){
                p++;
            }
            continue;
        }
        rep2(j, p, N){
            tmp *= s.at(j);
            if(tmp <= K){
                q++;
                if(j == N-1){
                    p = N-1;
                    break;
                }
            }
            else{
                tmp /= s.at(j);
                p = j;
                break;
            }
        }
        chmax(ans, q);
        tmp /= s.at(i);
    }
    cout << ans << endl;
}