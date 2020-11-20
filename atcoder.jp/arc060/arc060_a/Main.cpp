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
    ll N, A;
    cin >> N >> A;
    vector<ll> x(N);
    rep(i, N){
        cin >> x.at(i);
    }
    vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(N+1, vector<ll>(50*N+1, 0)));
    //dp.at(i).at(j).at(k)はi番目までのカードからj枚選んで合計をkにする組合せの数
    rep(i, N+1){
        dp.at(i).at(0).at(0) = 1;
    }
    rep(i, N){
        rep(j, i+1){
            rep(k, 50*N+1){
                if(x.at(i) > k){
                    dp.at(i+1).at(j+1).at(k) = dp.at(i).at(j+1).at(k);
                }
                else{
                    dp.at(i+1).at(j+1).at(k) = dp.at(i).at(j).at(k-x.at(i)) + dp.at(i).at(j+1).at(k);
                }
            }
        }
    }
    ll ans = 0;
    rep(i, N){
        ans += dp.at(N).at(i+1).at(A*(i+1));
    }
    cout << ans << endl;
}