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
    ll N, W;
    cin >> N >> W;
    vector<ll> S(N), T(N), P(N);
    rep(i, N){
        cin >> S.at(i) >> T.at(i) >> P.at(i);
    }
    vector<ll> imos(200005, 0);
    rep(i, N){
        imos.at(S.at(i)) += P.at(i);
        imos.at(T.at(i)) -= P.at(i);
    }
    rep(i, 200004){
        imos.at(i+1) += imos.at(i);
    }
    rep(i, 200005){
        if(imos.at(i) > W){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}