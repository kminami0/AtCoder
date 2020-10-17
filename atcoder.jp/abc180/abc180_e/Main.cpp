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
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N), Z(N);
    rep(i, N){
        cin >> X.at(i) >> Y.at(i) >> Z.at(i);
    }
    vector<vector<ll>> cost(N, vector<ll>(N));
    //cost.at(i).at(j)は都市iから都市jへ行くコスト
    rep(i, N){
        rep(j, N){
            cost.at(i).at(j) = abs(X.at(j)-X.at(i)) + abs(Y.at(j)-Y.at(i)) + max(0LL, Z.at(j)-Z.at(i));
        }
    }
    vector<vector<ll>> dp(1 << 17, vector<ll>(17, INF));
    // dp.at(i).at(j)は都市0を出発したあとにビット列iで指定される都市を1度以上巡って都市jに辿り着く最小コスト
    dp.at(0).at(0) = 0;
    rep(i, 1 << N){
        rep(j, N){
            rep(k, N){
                chmin(dp.at(i | (1 << j)).at(j), dp.at(i).at(k)+cost.at(k).at(j));
            }
        }
    }
    cout << dp.at((1 << N) -1).at(0) << endl;
}