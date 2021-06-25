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

vector<vector<bool>> vst(16, vector<bool>(16, false));
ll H, W;
ll sx, sy;
ll len;
ll cnt;
vector<string> c(16);

void dfs(ll x, ll y, ll d){
    if(x < 0 || x >= H || y < 0 || y >= W){
        return;
    }
    if(c.at(x).at(y) == '#'){
        return;
    }
    if(vst.at(x).at(y)){
        if(x == sx && y == sy){
            chmax(len, d);
        }
        return;
    }
    vst.at(x).at(y) = true;
    dfs(x+1, y, d+1);
    dfs(x-1, y, d+1);
    dfs(x, y+1, d+1);
    dfs(x, y-1, d+1);
    vst.at(x).at(y) = false;
}

int main()
{
    cin >> H >> W;
    rep(i, H){
        cin >> c.at(i);
    }
    ll ans = -1;
    rep(i, H){
        rep(j, W){
            rep(k, H){
                rep(l, W){
                    vst.at(k).at(l) = false;
                }
            }
            sx = i;
            sy = j;
            len = -1;
            dfs(i, j, 0);
            chmax(ans, len);
        }
    }
    if(ans < 3){
        cout << -1 << '\n';
    }
    else{
        cout << ans << '\n';
    }
}