#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
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
    ll p = 0;
    while(true){
        if(!S.count(p)){
            return p;
        }
        p++;
    }
}

int main()
{
    ll T;
    cin >> T;
    rep(i, T){
        ll N;
        cin >> N;
        vector<ll> L(N), R(N);
        rep(j, N){
            cin >> L.at(j) >> R.at(j);
        }
        vector<vector<ll>> dp(101, vector<ll>(101, 0));
        //dp.at(l).at(r)は[l, r)のGrundy数
        rep(j, 101){
            rep(k, 101-j){
                set<ll> S;
                rep(l, N){
                    if(k <= L.at(l) && R.at(l) <= k+j){
                        S.insert(dp.at(k).at(L.at(l)) ^ dp.at(R.at(l)).at(k+j));
                    }
                }
                dp.at(k).at(k+j) = mex(S);
            }
        }
        if(dp.at(0).at(100) == 0){
            cout << "Bob" << '\n';
        }
        else{
            cout << "Alice" << '\n';
        }
    }
}