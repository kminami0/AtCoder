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
    vector<string> S(N);
    rep(i, N){
        cin >> S.at(i);
    }
    ll ans = 0;
    rep(A, N){
        vector<string> T(N);
        rep(i, N){
            T.at(i) = S.at((i+A)%N);
        }
        bool sym = true;
        rep(i, N){
            rep(j, N){
                if(T.at(i).at(j) != T.at(j).at(i)){
                    sym = false;
                    break;
                }
            }
            if(!sym){
                break;
            }
        }
        if(sym){
            ans += N;
        }
    }
    cout << ans << endl;
}