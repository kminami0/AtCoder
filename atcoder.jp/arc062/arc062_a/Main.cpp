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
    vector<long double> T(N), A(N);
    rep(i, N){
        cin >> T.at(i) >> A.at(i);
    }
    vector<ll> t(N), a(N);
    t.at(0) = T.at(0);
    a.at(0) = A.at(0);
    rep(i, N-1){
        if(T.at(i+1)*(long double)(a.at(i)) >= (long double)(t.at(i))*A.at(i+1)){
            ll r = a.at(i) % (ll)(A.at(i+1));
            if(r != 0){
                a.at(i+1) = a.at(i) + A.at(i+1) - r;
            }
            else{
                a.at(i+1) = a.at(i);
            }
            t.at(i+1) = a.at(i+1) / (ll)(A.at(i+1)) * (ll)(T.at(i+1));
        }
        else{
            ll r = t.at(i) % (ll)(T.at(i+1));
            if(r != 0){
                t.at(i+1) = t.at(i) + T.at(i+1) - r;
            }
            else{
                t.at(i+1) = t.at(i);
            }
            a.at(i+1) = t.at(i+1) / (ll)(T.at(i+1)) * (ll)(A.at(i+1));
        }
    }
    cout << t.at(N-1) + a.at(N-1) << endl;
}