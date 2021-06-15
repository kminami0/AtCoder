#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
#define EPSILON 1e-14
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
    if(N == 3){
        cout << 6 << " " << 10 << " " << 15 << endl;
        return 0;
    }
    set<ll> A;
    A.insert(6);
    A.insert(10);
    A.insert(15);
    ll n = 12;
    while(n <= 10000){
        A.insert(n);
        n += 6;
    }
    n = 20;
    while(n <= 10000){
        A.insert(n);
        n += 10;
    }
    n = 30;
    while(n <= 10000){
        A.insert(n);
        n += 15;
    }
    ll cnt = 0;
    for(ll x : A){
        cout << x;
        cnt++;
        if(cnt == N){
            cout << endl;
            break;
        }
        cout << " ";
    }
}   