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
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> C(H, vector<ll>(W));
    rep(i, H){
        rep(j, W){
            cin >> C.at(i).at(j);
        }
    }
    ll ans = 0;
    vector<vector<ll>> black(H+1, vector<ll>(W+1, 0));
    vector<vector<ll>> white(H+1, vector<ll>(W+1, 0));
    rep(i, H){
        rep(j, W){
            if((i+j)%2 == 0){
                black.at(i+1).at(j+1) = black.at(i+1).at(j) + black.at(i).at(j+1) - black.at(i).at(j) + C.at(i).at(j);
                white.at(i+1).at(j+1) = white.at(i+1).at(j) + white.at(i).at(j+1) - white.at(i).at(j);
            }
            else{
                black.at(i+1).at(j+1) = black.at(i+1).at(j) + black.at(i).at(j+1) - black.at(i).at(j);
                white.at(i+1).at(j+1) = white.at(i+1).at(j) + white.at(i).at(j+1) - white.at(i).at(j) + C.at(i).at(j);
            }
        }
    }
    rep(i, H){
        rep2(j, i, H){
            rep(k, W){
                rep2(l, k, W){
                    ll b = black.at(j+1).at(l+1) - black.at(j+1).at(k) - black.at(i).at(l+1) + black.at(i).at(k);
                    ll w = white.at(j+1).at(l+1) - white.at(j+1).at(k) - white.at(i).at(l+1) + white.at(i).at(k);
                    if(b == w){
                        chmax(ans, (j-i+1)*(l-k+1));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}