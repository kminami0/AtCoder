#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
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
    ll V, A, B, C;
    cin >> V >> A >> B >> C;
    ll c = 0;
    while(true){
        if(c % 3 == 0){
            if(V < A){
                cout << 'F' << '\n';
                return 0;
            }
            V -= A;
        }
        else if(c % 3 == 1){
            if(V < B){
                cout << 'M' << '\n';
                return 0;
            }
            V -= B;
        }
        else{
            if(V < C){
                cout << 'T' << '\n';
                return 0;
            }
            V -= C;
        }
        c++;
    }
}