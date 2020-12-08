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
    ll N;
    cin >> N;
    vector<ll> P(N);
    rep(i, N) cin >> P.at(i);
    ll s = 1;
    vector<ll> ans(0);
    bool diff = false;
    rep(i, N){
        if(P.at(i) == s){
            if(i == s-1){
                cout << -1 << endl;
                return 0;
            }
            rep(j, i-s+1){
                ans.push_back(i-j);
            }
            s = i+1;
            diff = false;
        }
        else if(P.at(i) == i+1){
            cout << -1 << endl;
            return 0;
        }
        else if(P.at(i) != i+2 && !diff){
            diff = true;
        }
        else if(P.at(i) != i+1 && diff){
            cout << -1 << endl;
            return 0;
        }
    }
    if(sz(ans) != N-1){
        cout << -1 << endl;
        return 0;
    }
    rep(i, N-1){
        cout << ans.at(i) << endl;
    }
}