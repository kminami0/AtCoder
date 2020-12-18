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
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    ll k = N / 2;
    if(N % 2 == 1){
        rep(i, M){
            a.at(i) = k-i;
            b.at(i) = k+2+i;
        }
    }
    else{
        bool flag = false;
        ll p = 0;
        rep(i, M){
            a.at(i) = k-i;
            b.at(i) = k+2+i;
            if(b.at(i) - a.at(i) >= k){
                p = i;
                flag = true;
                break;
            }
        }
        if(flag){
            a.at(p)--;   
        }
        rep2(i, p+1, M){
            a.at(i) = a.at(i-1) - 1;
            b.at(i) = b.at(i-1) + 1;
        }
    }
    rep(i, M){
        cout << a.at(i) << " " << b.at(i) << endl;
    }
}