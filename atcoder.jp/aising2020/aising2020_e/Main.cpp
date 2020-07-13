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
    ll T;
    cin >> T;
    rep(i, T){
        ll N;
        cin >> N;
        vector<ll> K(N), L(N), R(N);
        rep(j, N){
            cin >> K.at(j) >> L.at(j) >> R.at(j);
        }
        ll base = 0;
        rep(j, N){
          ll m = min(L.at(j), R.at(j));
          base += m;
          L.at(j) -= m;
          R.at(j) -= m;
        }
        map<ll, vector<ll>> left;
        map<ll, vector<ll>> right;
        ll c = 0;
        rep(j, N){
          if(R.at(j) == 0){
            left[K.at(j)].push_back(L.at(j));
            c++;
          }
          else{
            right[K.at(j)+1].push_back(R.at(j));
          }
        }
        ll ans = base;
        priority_queue<ll> app;
        rep2(k, c+1, N+1){
          rep(l, sz(left[k])){
            app.push(left[k].at(l));
          }
        }
        rep(j, c){
          rep(k, sz(left[c-j])){
            app.push(left[c-j].at(k));
          }
          if(!app.empty()){
            ans += app.top();
            app.pop();
          }
        }
        priority_queue<ll> app2;
        rep(k, c){
          rep(l, sz(right[k+1])){
            app2.push(right[k+1].at(l));
          }
        }
        rep2(j, c+1, N+1){
          rep(k, sz(right[j])){
            app2.push(right[j].at(k));
          }
          if(!app2.empty()){
            ans += app2.top();
            app2.pop();
          }
        }
        cout << ans << endl;
    }
}