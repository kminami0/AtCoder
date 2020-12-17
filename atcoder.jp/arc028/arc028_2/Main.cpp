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
    vector<ll> X(N);
    rep(i, N) cin >> X.at(i);
    priority_queue<pair<ll, ll>> q;
    vector<ll> ans(0);
    rep(i, K){
        q.push({X.at(i), i+1});
    }
    rep(i, N-K+1){
        pair<ll, ll> p = q.top();
        ans.push_back(p.second);
        if(i < N-K){
            if(p.first > X.at(K+i)){
                q.pop();
                q.push({X.at(K+i), K+i+1});
            }
        }
    }
    rep(i, N-K+1){
        cout << ans.at(i) << endl;
    }
}