#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
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

struct edge {
  ll to;
};
vector<vector<edge>> rgraph;

int main()
{
    ll N, M, Q;
    cin >> N >> M >> Q;
    rgraph.resize(N);
    rep(i, M){
        ll X, Y;
        cin >> X >> Y;
        X--;
        Y--;
        rgraph[Y].push_back({X});
    }
    vector<ll> A(Q), B(Q);
    rep(i, Q){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    rep(i, Q/64){
        vector<ll> dp(N, 0);
        vector<ll> s(64), t(64);
        rep(j, 64){
            s[j] = A[64*i+j];
            t[j] = B[64*i+j];
        }
        rep(j, 64){
            dp[s[j]] += 1LL << j;
        }
        rep(j, N){
            for(edge e : rgraph[j]){
                dp[j] |= dp[e.to];
            }
        }
        rep(j, 64){
            if((dp[t[j]] & (1LL << j)) != 0){
                cout << "Yes" << '\n';
            }
            else{
                cout << "No" << '\n';
            }
        }
    }
    vector<ll> dp(N, 0);
    vector<ll> s((Q%64)), t((Q%64));
    rep(j, (Q%64)){
        s[j] = A[(Q/64)*64+j];
        t[j] = B[(Q/64)*64+j];
    }
    rep(j, (Q%64)){
        dp[s[j]] += 1LL << j;
    }
    rep(j, N){
        for(edge e : rgraph[j]){
            dp[j] |= dp[e.to];
        }
    }
    rep(j, (Q%64)){
        if((dp[t[j]] & (1LL << j)) != 0){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
        }
    }
}