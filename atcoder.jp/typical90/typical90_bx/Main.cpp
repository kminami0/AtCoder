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
    vector<ll> A(2*N);
    ll cake = 0;
    rep(i, N){
        cin >> A.at(i);
        cake += A.at(i);
    } 
    rep(i, N){
        A.at(N+i) = A.at(i);
    }
    if(cake % 10 != 0){
        cout << "No" << '\n';
        return 0;
    }
    cake /= 10;
    ll cut = 0;
    ll l = 0;
    rep(i, 2*N){
        cut += A.at(i);
        if(cut == cake){
            cout << "Yes" << '\n';
            return 0;
        }
        while(cut > cake){
            cut -= A.at(l);
            l++;
        }
        if(cut == cake){
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
}