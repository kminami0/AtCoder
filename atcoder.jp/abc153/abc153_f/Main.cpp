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
    ll N, D, A;
    cin >> N >> D >> A;
    vector<ll> X(N), H(N);
    rep(i, N){
        cin >> X.at(i) >> H.at(i);
    }
    vector<pair<ll, ll>> monster(N);
    rep(i, N){
        monster.at(i) = make_pair(X.at(i), H.at(i));
    }
    sort(all(monster));
    ll ans = 0;
    ll tot = 0;
    queue<pair<ll, ll>> q;
    rep(i, N){
      ll x = monster.at(i).first;
      ll h = monster.at(i).second;
      while(!q.empty() && q.front().first < x){
        tot -= q.front().second;
        q.pop();
      }
      h -= tot;
      if(h <= 0){
        continue;
      }
      ll c = (h+A-1)/A;
      ans += c;
      tot += A*c;
      q.push(make_pair(x+2*D, A*c));
    }
    cout << ans << endl; 
}