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
    ll L;
    cin >> L;
    vector<ll> B(L);
    rep(i, L) cin >> B.at(i);
    vector<ll> A(L);
    A.at(0) = 0;
    A.at(L-1) = 0;
    rep(i, L-1){
        A.at(L-1) = (A.at(L-1) ^ B.at(i));
    }
    rep(i, L-1){
        A.at(L-2-i) = (B.at(L-2-i) ^ A.at(L-1-i));
    }
    rep(i, L-1){
        if(B.at(i) != (A.at(i) ^ A.at(i+1))){
            cout << -1 << endl;
            return 0;
        }
    }
    if(B.at(L-1) != (A.at(L-1) ^ A.at(0))){
        cout << -1 << endl;
        return 0;
    }
    rep(i, L){
        cout << A.at(i) << endl;
    }
}