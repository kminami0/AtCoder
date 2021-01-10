#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 10000000000000000 //10^16
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
    vector<ll> A(1 << N);
    rep(i, 1 << N) cin >> A.at(i);
    map<ll, ll> player;
    rep(i, 1 << N){
        player[A.at(i)] = i;
    }
    rep(i, N-1){
        rep(j, 1 << (N-1-i)){
            A.at(j) = max(A.at(2*j), A.at(2*j+1));
        }
    }
    cout << player.at(min(A.at(0), A.at(1)))+1 << endl;
}