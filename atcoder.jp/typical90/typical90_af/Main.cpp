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
    ll N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N));
    rep(i, N){
        rep(j, N){
            cin >> A.at(i).at(j);
        }
    }
    ll M;
    cin >> M;
    set<pair<ll, ll>> ng;
    rep(i, M){
        ll X, Y;
        cin >> X >> Y;
        X--;
        Y--;
        ng.insert({X, Y});
        ng.insert({Y, X});
    }
    vector<ll> v(0);
    rep(i, N){
        v.push_back(i);
    }
    ll ans = INF;
    do{
        ll time = 0;
        bool flag = false;
        rep(i, N-1){
            if(ng.count({v.at(i), v.at(i+1)})){
                flag = true;
                break;
            }
            time += A.at(v.at(i)).at(i);
        }
        if(!flag){
            time += A.at(v.at(N-1)).at(N-1);
            chmin(ans, time);
        }
    } while(next_permutation(all(v)));
    if(ans == INF){
        cout << -1 << '\n';
    }
    else{
        cout << ans << '\n';
    }
}