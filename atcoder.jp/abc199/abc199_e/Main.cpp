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
int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> X(M), Y(M), Z(M);
    rep(i, M){
        cin >> X.at(i) >> Y.at(i) >> Z.at(i);
    }
    vector<ll> dp(1 << N, 0);
    dp.at(0) = 1;
    rep(i, 1 << N){
        ll cnt = 0;
        bitset<18> s(i);
        rep(j, N){
            if(s.test(j)){
                cnt++;
            }
        }
        rep(j, N){
            if((i & (1 << j)) == 0){
                bitset<18> t(i | (1 << j));
                bool flag = false;
                rep(k, M){
                    if(X.at(k) == cnt + 1){
                        ll c = 0;
                        rep(l, Y.at(k)){
                            if(t.test(l)){
                                c++;
                            }
                            if(c > Z.at(k)){
                                flag = true;
                                break;
                            }
                        }
                    }
                    if(flag){
                        break;
                    }
                }
                if(!flag){
                    dp.at(i | (1 << j)) += dp.at(i);
                }
            }
        }
    }
    cout << dp.at((1 << N) - 1) << '\n';
}