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
    vector<vector<ll>> D(N, vector<ll>(2));
    rep(i, N){
        rep(j, 2){
            cin >> D.at(i).at(j);
        }
    }
    ll zoro = 0;
    rep(i, N){
        if(D.at(i).at(0) == D.at(i).at(1)){
            zoro++;
            if(zoro == 3){
                cout << "Yes" << endl;
                return 0;
            }
        }
        else{
            zoro = 0;
        }
    }
    cout << "No" << endl;
}