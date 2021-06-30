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
    vector<vector<ll>> A(H, vector<ll>(W));
    vector<vector<ll>> B(H, vector<ll>(W));
    rep(i, H){
        rep(j, W){
            cin >> A.at(i).at(j);
        }
    }
    rep(i, H){
        rep(j, W){
            cin >> B.at(i).at(j);
        }
    }
    ll ans = 0;
    rep(i, H-1){
        rep(j, W-1){
            if(A.at(i).at(j) < B.at(i).at(j)){
                ll d = B.at(i).at(j) - A.at(i).at(j);
                A.at(i).at(j) += d;
                A.at(i).at(j+1) += d;
                A.at(i+1).at(j) += d;
                A.at(i+1).at(j+1) += d;
                ans += d;
            }
            else if(A.at(i).at(j) > B.at(i).at(j)){
                ll d = A.at(i).at(j) - B.at(i).at(j);
                A.at(i).at(j) -= d;
                A.at(i).at(j+1) -= d;
                A.at(i+1).at(j) -= d;
                A.at(i+1).at(j+1) -= d;
                ans += d;
            }
        }
    }
    rep(i, H){
        if(A.at(i).at(W-1) != B.at(i).at(W-1)){
            cout << "No" << '\n';
            return 0;
        }
    }
    rep(i, W){
        if(A.at(H-1).at(i) != B.at(H-1).at(i)){
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';
    cout << ans << '\n';
}