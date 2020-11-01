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
    vector<ll> x(N), y(N);
    rep(i, N){
        cin >> x.at(i) >> y.at(i);
    }
    rep(i, N){
        rep2(j, i+1, N){
            rep2(k, j+1, N){
                ll dx1 = x.at(j)-x.at(i);
                ll dx2 = x.at(k)-x.at(i);
                ll dy1 = y.at(j)-y.at(i);
                ll dy2 = y.at(k)-y.at(i);
                if(dx2*dy1 == dx1*dy2){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}