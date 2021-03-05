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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    string A, B;
    cin >> A >> B;
    vector<vector<ll>> dp(sz(A)+1, vector<ll>(2, 0));
    dp.at(0).at(0) = 1;
    rep(i, sz(A)){
        rep(j, 2){
            rep(d, (j?9:A.at(i)-'0')+1){
                if(d == 4 || d == 9){
                    continue;
                }
                dp.at(i+1).at(j || (d<A.at(i)-'0')) += dp.at(i).at(j);
            }
        }
    }
    ll s = dp.at(sz(A)).at(1) + dp.at(sz(A)).at(0); //A以下で使ってよい数の個数
    vector<vector<ll>> dp2(sz(B)+1, vector<ll>(2, 0));
    dp2.at(0).at(0) = 1;
    rep(i, sz(B)){
        rep(j, 2){
            rep(d, (j?9:B.at(i)-'0')+1){
                if(d == 4 || d == 9){
                    continue;
                }
                dp2.at(i+1).at(j || (d<B.at(i)-'0')) += dp2.at(i).at(j);
            }
        }
    }
    ll t = dp2.at(sz(B)).at(1) + dp2.at(sz(B)).at(0); //B以下で使ってよい数の個数
    bool ok = true;
    rep(i, sz(A)){
        if(A.at(i) == '4' || A.at(i) == '9'){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << (stoll(B) - t) - (stoll(A)-s) << '\n';
    }
    else{
        cout << (stoll(B) - t) - (stoll(A)-s) + 1 << '\n';
    }
}