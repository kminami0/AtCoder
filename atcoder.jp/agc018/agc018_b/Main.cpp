#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> A(N, vector<ll>(M));
    rep(i, N){
        rep(j, M){
            cin >> A.at(i).at(j);
        }
    }
    ll ans = INF;
    rep(i, M){
        map<ll, ll> p;
        rep(i, N){
            p[A.at(i).at(0)]++;
        }
        ll tmp = 0;
        ll pop = 0;
        for(auto q : p){
            if(chmax(tmp, q.second)){
                pop = q.first;
            }
        }
        chmin(ans, tmp);
        rep(j, N){
            remove(begin(A.at(j)), begin(A.at(j))+M-i, pop);
        }
    }
    cout << ans << '\n';
}