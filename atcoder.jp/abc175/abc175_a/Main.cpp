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
    string S;
    cin >> S;
    ll c = 0;
    if(S == "RRR"){
        cout << 3 << endl;
    }
    else if(S == "RRS" || S == "SRR"){
        cout << 2 << endl;
    }
    else if(S == "RSR" || S == "RSS" || S == "SRS" || S == "SSR"){
        cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }
}