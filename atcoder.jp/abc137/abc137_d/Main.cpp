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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N), B(N);
    map<ll, vector<ll>> work;
    rep(i, N){
        cin >> A.at(i) >> B.at(i);
        work[A.at(i)].push_back(B.at(i));
    }
    priority_queue<ll> app;
    ll ans = 0;
    rep(i, M){
        rep(j, sz(work[i+1])){
            app.push(work[i+1].at(j));
        }
        if(!app.empty()){
            ans += app.top();
            app.pop();
        }
    }
    cout << ans << endl;
}