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
    string A;
    cin >> A;
    ll um = 0;
    rep(i, sz(A)/2){
        if(A.at(i) != A.at(sz(A)-1-i)){
            um++;
        }
        if(um > 1){
            cout << 25*sz(A) << endl;
            return 0;
        }
    }
    if(sz(A)%2 == 1 && um == 0){
        cout << 25*sz(A)-25 << endl;
        return 0;
    }
    if(sz(A)%2 == 1 && um == 1){
        cout << 25*sz(A)-2 << endl;
        return 0;
    }
    if(sz(A)%2 == 0 && um == 0){
        cout << 25*sz(A) << endl;
        return 0;
    }
    if(sz(A)%2 == 0 && um == 1){
        cout << 25*sz(A)-2 << endl;
        return 0;
    }
}