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

ll H, W;
vector<vector<bool>> used(16, vector<bool>(16, false));

ll dfs(ll i, ll j, ll a, ll b){
    if(a < 0 || b < 0){
        return 0;
    }
    if(j == W){
        j = 0;
        i++;
    }
    if(i == H){
        return 1;
    }
    if(used.at(i).at(j)){
        return dfs(i, j+1, a, b);
    }
    ll res = 0;
    used.at(i).at(j) = true;
    res += dfs(i, j+1, a, b-1);
    if(j+1 < W){
        if(!used.at(i).at(j+1)){
            used.at(i).at(j+1) = true;
            res += dfs(i, j+1, a-1, b);
            used.at(i).at(j+1) = false;
        }
    }
    if(i+1 < H){
        if(!used.at(i+1).at(j)){
            used.at(i+1).at(j) = true;
            res += dfs(i, j+1, a-1, b);
            used.at(i+1).at(j) = false;
        }
    }
    used.at(i).at(j) = false;
    return res;
}

int main()
{
    ll A, B;
    cin >> H >> W >> A >> B;
    cout << dfs(0, 0, A, B) << '\n';   
}