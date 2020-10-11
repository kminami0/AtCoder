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
    vector<ll> a(N);
    rep(i, N) cin >> a.at(i);
    sort(all(a));
    while(a.at(0) != a.at(N-1)){
        rep2(i, 1, N){
            a.at(i) %= a.at(0);
            if(a.at(i) == 0){
                a.at(i) = a.at(0);
            }
        }
        sort(all(a));
    }
    cout << a.at(0) << endl;
}