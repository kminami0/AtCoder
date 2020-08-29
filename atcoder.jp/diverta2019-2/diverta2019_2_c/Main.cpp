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
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    sort(all(A));
    ll p = N;
    rep(i, N){
      if(A.at(i) > 0){
        p = i;
        break;
      }
    }
    ll M = 0;
    M += A.at(N-1);
    M -= A.at(0);
    rep(i, N-2){
      if(i+1 >= p){
        M += A.at(i+1);
      }
      else{
        M -= A.at(i+1);
      }
    }
    cout << M << endl;
    ll x = A.at(0);
    if(p == 0){
      p++;
    }
    if(p == N){
      p--;
    }
    rep2(j, p, N-1){
      cout << x << " " << A.at(j) << endl;
      x -= A.at(j);
    }
    ll y = A.at(N-1);
    rep2(i, 1, p){
      cout << y << " " << A.at(i) << endl;
      y -= A.at(i);
    }
    cout << y << " " << x << endl;
}