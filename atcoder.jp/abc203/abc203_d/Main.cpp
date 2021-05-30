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
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> A(N, vector<ll>(N));
    rep(i, N){
        rep(j, N){
            cin >> A.at(i).at(j);
        }
    }
    ll l = 0;
    ll r = INF;
    //中央値をr未満にできl未満にできない
    while(r-l>1){
        ll c = (l+r) / 2;
        vector<vector<ll>> B(N, vector<ll>(N));
        rep(i, N){
            rep(j, N){
                if(A.at(i).at(j) >= c){
                    B.at(i).at(j) = 1;
                }
                else{
                    B.at(i).at(j) = -1;
                }
            }
        }
        vector<vector<ll>> acc(N+1, vector<ll>(N+1, 0));
        rep(i, N){
            rep(j, N){
                acc.at(i+1).at(j+1) = acc.at(i).at(j+1) + acc.at(i+1).at(j) - acc.at(i).at(j) + B.at(i).at(j);
            }
        }
        bool flag = false;
        rep(i, N-K+1){
            rep(j, N-K+1){
                ll sum = acc.at(i+K).at(j+K) - acc.at(i).at(j+K) - acc.at(i+K).at(j) + acc.at(i).at(j);
                if(sum <= 0){ //c以上が半分以下 <=> 中央値はc未満
                    r = c;
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            l = c;
        }
    }
    cout << l << '\n';
}