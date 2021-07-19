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
    ll H, W, C;
    cin >> H >> W >> C;
    vector<vector<ll>> A(H, vector<ll>(W));
    rep(i, H){
        rep(j, W){
            cin >> A.at(i).at(j);
        }
    }
    vector<vector<ll>> m(H, vector<ll>(W));
    m.at(0).at(0) = INF;
    rep(i, H){
        rep(j, W){
            if(i == 0 && j == 0){
                continue;
            }
            if(i == 0){
                m.at(i).at(j) = min(m.at(i).at(j-1), A.at(i).at(j-1) - C * (i + j - 1));
            }
            else if(j == 0){
                m.at(i).at(j) = min(m.at(i-1).at(j), A.at(i-1).at(j) - C * (i - 1 + j));
            }
            else{
                m.at(i).at(j) = min(min(m.at(i).at(j-1), A.at(i).at(j-1) - C * (i + j - 1)),min(m.at(i-1).at(j), A.at(i-1).at(j) - C * (i - 1 + j)));
            }
        }
    }
    ll ans = INF;
    rep(i, H){
        rep(j, W){
            chmin(ans, A.at(i).at(j) + C * (i + j) + m.at(i).at(j));
        }
    }
    rep(i, H){
        reverse(all(A.at(i)));
    }
    m.at(0).at(0) = INF;
    rep(i, H){
        rep(j, W){
            if(i == 0 && j == 0){
                continue;
            }
            if(i == 0){
                m.at(i).at(j) = min(m.at(i).at(j-1), A.at(i).at(j-1) - C * (i + j - 1));
            }
            else if(j == 0){
                m.at(i).at(j) = min(m.at(i-1).at(j), A.at(i-1).at(j) - C * (i - 1 + j));
            }
            else{
                m.at(i).at(j) = min(min(m.at(i).at(j-1), A.at(i).at(j-1) - C * (i + j - 1)),min(m.at(i-1).at(j), A.at(i-1).at(j) - C * (i - 1 + j)));
            }
        }
    }
    rep(i, H){
        rep(j, W){
            chmin(ans, A.at(i).at(j) + C * (i + j) + m.at(i).at(j));
        }
    }
    cout << ans << '\n';
}