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
    ll N, D;
    cin >> N >> D;
    vector<ll> X(N), Y(N);
    rep(i, N){
        cin >> X.at(i) >> Y.at(i);
    }
    ll c = 0;
    rep(i, N){
        if(X.at(i)*X.at(i) + Y.at(i)*Y.at(i) <= D*D){
            c++;
        }
    }
    cout << c << endl;
}