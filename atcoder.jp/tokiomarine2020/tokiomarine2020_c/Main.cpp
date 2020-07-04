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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    rep(i, min(100LL, K)){
        vector<ll> imos(N+1, 0);
        rep(i, N){
            imos.at(max(i - A.at(i), 0LL))++;
            imos.at(min(i + A.at(i) + 1, N))--;
        }
//        rep(i, N+1){
//            cout << imos.at(i) << " ";
//        }
//        cout << endl;
        A.at(0) = imos.at(0);
        rep(i, N-1){
            A.at(i+1) = A.at(i) + imos.at(i+1);
        }
    }
    rep(i, N-1){
        cout << A.at(i) << " ";
    }
    cout << A.at(N-1) << endl;
}