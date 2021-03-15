#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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

ll mex(set<ll> S){
    ll a = 0;
    while(true){
        if(!S.count(a)){
            return a;
        }
        a++;
    }
}

int main()
{
    ll N;
    string S, X;
    cin >> N >> S >> X;
    vector<vector<bool>> dp(N+1, vector<bool>(7, false));
    //dp.at(i).at(j)はi回目のラウンド終了時に余りがjであったときに高橋君が勝つかどうか
    dp.at(N).at(0) = true;
    rep(i, N){
        rep(j, 7){
            if(X.at(N-1-i) == 'T'){
                dp.at(N-1-i).at(j) = dp.at(N-i).at(10*j%7) || dp.at(N-i).at((10*j+S.at(N-1-i)-'0')%7);
            }
            else{
                dp.at(N-1-i).at(j) = dp.at(N-i).at(10*j%7) && dp.at(N-i).at((10*j+S.at(N-1-i)-'0')%7);
            }
        }
    }
    if(dp.at(0).at(0)){
        cout << "Takahashi" << '\n';
    }
    else{
        cout << "Aoki" << '\n';
    }
}