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
    if(N % 2 == 1){
        ll k = (N-1)/2;
        cout << 2*k*k << endl;
        rep(i, k){
            rep(j, k-i-1){
                cout << i+1 << " " << i+j+2 << endl;
                cout << i+1 << " " << 2*k-i-j-1 << endl;
                cout << 2*k-i << " " << i+j+2 << endl;
                cout << 2*k-i << " " << 2*k-i-j-1 << endl;
            }
            cout << i+1 << " " << 2*k+1 << endl;
            cout << 2*k-i << " " << 2*k+1 << endl;
        }
    }
    else{
        ll k = N / 2;
        cout << 2*k*(k-1) << endl;
        rep(i, k){
            rep(j, k-i-1){
                cout << i+1 << " " << i+j+2 << endl;
                cout << i+1 << " " << 2*k-i-j-1 << endl;
                cout << 2*k-i << " " << i+j+2 << endl;
                cout << 2*k-i << " " << 2*k-i-j-1 << endl;
            }
        }
    }
}