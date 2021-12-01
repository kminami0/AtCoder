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
int main()
{
    ll H, W, C, Q;
    cin >> H >> W >> C >> Q;
    vector<ll> t(Q), n(Q), c(Q);
    rep(i, Q){
        cin >> t.at(i) >> n.at(i) >> c.at(i);
        n.at(i)--;
        c.at(i)--;
    }
    vector<ll> ans(C, 0);
    vector<bool> used_row(H, false);
    vector<bool> used_col(W, false);
    ll row_cnt = 0;
    ll col_cnt = 0;
    for(ll i = Q-1; i >= 0; i--){
        if(t.at(i) == 1){
            if(!used_row.at(n.at(i))){
                used_row.at(n.at(i)) = true;
                ans.at(c.at(i)) += W - col_cnt;
                row_cnt++;
            }
        }
        else{
            if(!used_col.at(n.at(i))){
                used_col.at(n.at(i)) = true;
                ans.at(c.at(i)) += H - row_cnt;
                col_cnt++;
            }
        }
    }
    rep(i, C-1){
        cout << ans.at(i) << ' ';
    }
    cout << ans.at(C-1) << '\n';
}