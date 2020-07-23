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
    ll N, C;
    cin >> N >> C;
    vector<vector<ll>> D(C, vector<ll>(C));
    rep(i, C){
        rep(j, C){
            cin >> D.at(i).at(j);
        }
    }
    vector<vector<ll>> c(N, vector<ll>(N));
    rep(i, N){
        rep(j, N){
            cin >> c.at(i).at(j);
            c.at(i).at(j)--;
        }
    }
    vector<vector<ll>> iwa(3, vector<ll>(C, 0));
    rep(i, N){
        rep(j, N){
            ll a = (i+j)%3;
            rep(k, C){
                iwa.at(a).at(k) += D.at(c.at(i).at(j)).at(k);
            }
        }
    }
    ll ans = INF;
    rep(i, C){
        rep(j, C){
            if(j == i){
                continue;
            }
            rep(k, C){
                if(k == i || k == j){
                    continue;
                }
                chmin(ans, iwa.at(0).at(i)+iwa.at(1).at(j)+iwa.at(2).at(k));
            }
        }
    }
    cout << ans << endl;
}