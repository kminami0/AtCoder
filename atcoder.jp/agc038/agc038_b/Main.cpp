#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
#define INF 1e18+999999
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
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N);
    rep(i, N) cin >> P.at(i);
    if(K == N){
        cout << 1 << '\n';
        return 0;
    }
    vector<ll> inc(N-1, 0);
    rep(i, N-1){
        if(P.at(i) < P.at(i+1)){
            inc.at(i) = 1;
        }
    }
    vector<ll> acc(N, 0);
    rep(i, N-1){
        acc.at(i+1) = acc.at(i) + inc.at(i);
    }
    set<ll> S;
    rep(i, K){
        S.insert(P.at(i));
    }
    bool flag = (acc.at(K-1) == K-1);
    ll ans = 0;
    if(!flag){
        ans = 1;
    }
    rep(i, N-K){
        bool flag2 = (*begin(S) == P.at(i));
        S.erase(P.at(i));
        S.insert(P.at(i+K));
        flag2 &= (*rbegin(S) == P.at(i+K));
        if(acc.at(i+K) - acc.at(i+1) == K-1){
            flag = true;
        }
        else if(!flag2){
            ans++;
        }
    }
    if(flag){
        ans++;
    }
    cout << ans << '\n';
}