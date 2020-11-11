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
    ll N, T;
    cin >> N >> T;
    vector<pair<ll, ll>> food(N);
    rep(i, N){
        ll A, B;
        cin >> A >> B;
        food.at(i) = {A, B};
    }
    sort(all(food));
    vector<vector<ll>> dp(N+1, vector<ll>(T+1, 0));
    //dp.at(i).at(j)は食べるのにかかる時間の短さがi番目までの料理をj分以内に食べ終わるときの最大満足度
    //ただしj=Tのときは最後に食べたものはT分以内に食べ終わっていなくてもよいとする
    rep(i, N){
        rep(j, T+1){
            if(j < T){
                if(j >= food.at(i).first){
                    dp.at(i+1).at(j) = max(dp.at(i).at(j-food.at(i).first)+food.at(i).second, dp.at(i).at(j));
                }
                else{
                    dp.at(i+1).at(j) = dp.at(i).at(j);
                }
            }
            else{
                dp.at(i+1).at(T) = max(dp.at(i).at(T-1)+food.at(i).second, dp.at(i).at(T));
            }
        }
    }
    cout << dp.at(N).at(T) << endl;
}