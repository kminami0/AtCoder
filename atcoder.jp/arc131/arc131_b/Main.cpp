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
    ll H, W;
    cin >> H >> W;
    vector<string> c(H);
    rep(i, H){
        cin >> c.at(i);
    }
    rep(i, H){
        rep(j, W){
            if(c.at(i).at(j) == '.'){
                set<char> used;
                if(i > 0){
                    used.insert(c.at(i-1).at(j));
                }
                if(i < H-1){
                    used.insert(c.at(i+1).at(j));
                }
                if(j > 0){
                    used.insert(c.at(i).at(j-1));
                }
                if(j < W-1){
                    used.insert(c.at(i).at(j+1));
                }
                rep(k, 5){
                    if(!used.count(k+'1')){
                        c.at(i).at(j) = k + '1';
                        break;
                    }
                }
            }
        }
    }
    rep(i, H){
        cout << c.at(i) << '\n';
    }
}